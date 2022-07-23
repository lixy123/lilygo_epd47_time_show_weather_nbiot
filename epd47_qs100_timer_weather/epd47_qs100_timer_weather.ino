#include <HardwareSerial.h>
#include "RTClib.h"
#include "hz3500_36.h"
#include "hz3500_16.h"
#include "showweather.h"

//https 还未调试成功
//调用会重启！
//编译文件大小 1.1M
HardwareSerial mySerial(1);
RTC_Millis rtc;

//墨水屏缓存区
uint8_t *framebuffer;
weatherManager* obweatherManager;

const int short_time_segment = 60;  //休眠唤醒最小分钟时间间隔
uint32_t TIME_TO_SLEEP = 3600; //下次唤醒间隔时间(3600秒）

bool net_connect_succ = false;

int starttime, stoptime;

String weather_data_table = ""; //天气json字符串

bool state_sync_time = false;
bool  state_sync_weather = false;

String http_weather_host = "http://api.seniverse.com";
String http_weather_url = "/v3/weather/daily.json?key=urfcfaxdk4zxr3z0&location=beijing&language=zh-Hans&unit=c&start=0&days=3";


int cnt_check_net = 0;

int cnt_sync_weather = 0;

char daysOfTheWeek[7][12] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

#define uS_TO_S_FACTOR 1000000ULL  /* Conversion factor for micro seconds to seconds */
hw_timer_t *timer = NULL;

String buff_split[20];

/*
  通过esp32墨水屏+ qt100(nbiot模块)
  每天7点左右通过NBIOT获取并显示天气
  完成时间，天气同步平均时间：70秒
  3分钟如果不执行完全部操作会自动重启,防止因为程序跑飞耗尽电池
  如果未正确同步时间，2小时后会再试
  没考虑0-7点esp32重新上电

  1.获取天气
     网址:

  2.获取时间
     网址: 通过，
    如果得到当前时间，计算休眠时间，直到次日7点唤醒。(正常情况)
    如果未得到当前时间，休眠2小时再试。

  电流：50ma

  编译大小: 3.4M
  开发板选择: TTGO-W-WATCH (仅用到分区定义，原因为汉字库较大)

  偶尔发现usb供电时，qs100不供电，但电池供电没事！可能是墨水屏3.3V电流供电输出的问题
*/

void IRAM_ATTR resetModule() {
  ets_printf("resetModule reboot\n");
  delay(100);
  //esp_restart_noos(); 旧api
  esp_restart();
}

//毫秒内不接收串口数据，并清缓存
void clear_uart(int ms_time)
{
  //唤醒完成后就可以正常接收串口数据了
  uint32_t starttime = 0;
  char ch;
  //5秒内有输入则输出
  starttime = millis();
  //临时接收缓存，防止无限等待
  while (true)
  {
    if  (millis()  - starttime > ms_time)
      break;
    while (mySerial.available())
    {
      ch = (char) mySerial.read();
      Serial.print(ch);
    }
    yield();
    delay(20);
  }
}


bool get_weather()
{
  bool succ_flag = false;

  String ret;
  cnt_sync_weather = cnt_sync_weather + 1;


  free_http();
  delay(1000);

  weather_data_table = "";

  //注意： qs-100 最后不需要 "/"
  ret = send_at("AT+HTTPCREATE=\"" + http_weather_host + "\"", "OK", 3);
  Serial.println("ret=" + ret);
  if (not (ret.indexOf("+HTTPCREATE:0") > -1))
    return false;

  Serial.println(">>> 创建HTTP Host ok ...");
  delay(2000);


  Serial.println(">>> 获取数据 ...");
  //最长120秒内获得数据
  ret = send_at_httpget("AT+HTTPSEND=0,0,\"" + http_weather_url + "\"", 60);
  //Serial.println("ret=" + ret);
  if  (ret.length() > 200)
  {
    succ_flag = true;
    weather_data_table = ret;
    Serial.println("weather=" + weather_data_table);
  }

  delay(500);

  return succ_flag;
}

//readStringUntil 注意：如果一直等不到结束符会阻塞
String send_at2(String p_char, String break_str, String break_str2, int delay_sec) {

  String ret_str = "";
  String tmp_str = "";
  if (p_char.length() > 0)
  {
    Serial.println(String("cmd=") + p_char);
    mySerial.println(p_char);
  }

  //发完命令立即退出
  //if (break_str=="") return "";

  mySerial.setTimeout(1000);

  uint32_t start_time = millis() / 1000;
  while (millis() / 1000 - start_time < delay_sec)
  {
    if (mySerial.available() > 0)
    {

      tmp_str = mySerial.readStringUntil('\n');
      //tmp_str.replace("\r", "");
      tmp_str = tmp_str.substring(0, tmp_str.length() - 1); //去掉串尾的 \r
      //tmp_str.trim()  ;
      Serial.println(">" + tmp_str);
      //如果字符中有特殊字符，用 ret_str=ret_str+tmp_str会出现古怪问题，最好用concat函数
      ret_str.concat(tmp_str);
      if (break_str.length() > 0 && tmp_str.indexOf(break_str) > -1 )
        break;
      if (break_str2.length() > 0 &&  tmp_str.indexOf(break_str2) > -1 )
        break;
    }
    delay(10);
  }
  return ret_str;
}


//readStringUntil 注意：如果一直等不到结束符会阻塞
String send_at(String p_char, String break_str, int delay_sec) {

  String ret_str = "";
  String tmp_str = "";
  if (p_char.length() > 0)
  {
    Serial.println(String("cmd=") + p_char);
    mySerial.println(p_char);
  }

  //发完命令立即退出
  //if (break_str=="") return "";

  mySerial.setTimeout(1000);

  uint32_t start_time = millis() / 1000;
  while (millis() / 1000 - start_time < delay_sec)
  {
    if (mySerial.available() > 0)
    {
      tmp_str = mySerial.readStringUntil('\n');
      //tmp_str.replace("\r", "");
      tmp_str = tmp_str.substring(0, tmp_str.length() - 1); //去掉串尾的 \r
      //tmp_str.trim()  ;
      Serial.println(">" + tmp_str);
      //如果字符中有特殊字符，用 ret_str=ret_str+tmp_str会出现古怪问题，最好用concat函数
      ret_str.concat(tmp_str);
      if (break_str.length() > 0 && tmp_str.indexOf(break_str) > -1)
        break;
    }
    delay(10);
  }
  return ret_str;
}

//检查是否关机状态
bool check_waker_7020()
{
  String ret = "";
  delay(1000);
  int cnt = 0;
  bool check_ok = false;
  //通过AT命令检查是否关机，共检查3次
  while (true)
  {
    cnt++;

    //不要用 send_at("AT", "", 2);
    //如果一直收不到 \n 字串，程序会阻塞
    ret = send_at("AT", "", 2);
    Serial.println("ret=" + ret);
    if (ret.indexOf("OK") > -1)
    {
      check_ok = true;
      break;
    }
    if (cnt >= 5) break;
    delay(1000);
  }
  return check_ok;
}



bool connect_nb()
{
  bool  ret_bool = false;

  int error_cnt = 0;
  String ret;

  cnt_check_net = cnt_check_net + 1;
  Serial.println(">>> 检查网络连接状态 ...");
  error_cnt = 0;
  //网络注册状态
  while (true)
  {
    ret = send_at("AT+CEREG?", "OK", 3);
    Serial.println("ret=" + ret);
    if (ret.indexOf("+CEREG:0,1") > -1)
      break;
    delay(2000);

    error_cnt++;
    if (error_cnt >= 5)
      return false;
  }
  Serial.println(">>> 网络注册状态 ok ...");
  delay(1000);


  error_cnt = 0;
  //查询附着状态
  while (true)
  {
    ret = send_at("AT+CGATT?", "OK", 3);
    Serial.println("ret=" + ret);

    if (ret.indexOf("+CGATT:1") > -1)
      break;
    delay(2000);

    error_cnt++;
    if (error_cnt >= 5)
      return false;
  }
  Serial.println(">>> 附着状态 ok ...");

  delay(1000);

  error_cnt = 0;
  //查询附着状态
  while (true)
  {
    ret = send_at("AT+CCLK?", "OK", 3);
    Serial.println("ret=" + ret);

    if (ret.indexOf("+CCLK:") > -1)
      break;
    delay(2000);

    error_cnt++;
    if (error_cnt >= 5)
      return false;
  }

  Serial.println(">>> 获取时间成功 ...");
  //+CCLK:22/07/15,13:36:45+32OK
  state_sync_time = false;
  if (ret.startsWith("+CCLK:22/"))
  {
    state_sync_time = true;
    ret.replace("OK", "");
    Serial.println("获取时间:" + ret);
    sync_esp32_rtc(ret);
  }

  cnt_check_net = 0;
  return true;
}

//把 +CCLK:22/07/14,14:50:41+32 转换成esp32内的时间
void sync_esp32_rtc(String now_time)
{
  now_time.replace("+CCLK:", "##");
  DateTime now = DateTime(now_time.substring(2, 4).toInt() + 2000, now_time.substring(5, 7).toInt(), now_time.substring(8, 10).toInt(),
                          now_time.substring(11, 13).toInt(), now_time.substring(14, 16).toInt(), now_time.substring(17, 19).toInt());
  // calculate a date which is 7 days and 30 seconds into the future
  //增加8小时
  DateTime future (now.unixtime() + 28800L);
  rtc.adjust(future);
  Serial.println("now_time:" + Get_softrtc_time(6));
}

void splitString(String message, String dot, String outmsg[], int len)
{
  int commaPosition, outindex = 0;
  for (int loop1 = 0; loop1 < len; loop1++)
    outmsg[loop1] = "";
  do {
    commaPosition = message.indexOf(dot);
    if (commaPosition != -1)
    {
      outmsg[outindex] = message.substring(0, commaPosition);
      outindex = outindex + 1;
      message = message.substring(commaPosition + 1, message.length());
    }
    if (outindex >= len) break;
  }
  while (commaPosition >= 0);

  if (outindex < len)
    outmsg[outindex] = message;
}

int parse_CHTTPNMIC(String in_str)
{
  //+HTTPNMIC:0,1,5231,815
  String out_str = "";
  int cnt = 0;
  splitString(in_str, ",", buff_split, 4);
  cnt = buff_split[3].toInt() ;
  return cnt;
}


String send_at_httpget(String p_char, int delay_sec) {
  String ret_str = "";
  String tmp_str = "";
  if (p_char.length() > 0)
  {
    Serial.println(String("cmd=") + p_char);
    mySerial.println(p_char);
  }
  ret_str = "";
  mySerial.setTimeout(5000);
  uint32_t start_time = millis() / 1000;
  int content_len;
  while (millis() / 1000 - start_time < delay_sec)
  {

    if (mySerial.available() > 0)
    {
      tmp_str = mySerial.readStringUntil('\n');
      tmp_str = tmp_str.substring(0, tmp_str.length() - 1); //去掉串尾的 \r

      Serial.println(tmp_str);
      //数据接收完成，正常退出
      if (tmp_str.startsWith("+HTTPDICONN:0,-2"))
      {
        Serial.println("数据接收完毕,break");
        break;
      }

      if (tmp_str.startsWith("+REQUESTSUCCESS") )
      {
        Serial.println("开始数据接收...");
        //break;
      }

      //没有获得数据
      if (tmp_str.startsWith("+BADREQUEST"))
      {
        Serial.println("未获得数据,break");
        break;
      }

      if (tmp_str.startsWith("+HTTPNMIC:0,"))
      {
        content_len = parse_CHTTPNMIC(tmp_str);
        tmp_str = mySerial.readStringUntil('\n');
        tmp_str = tmp_str.substring(0, tmp_str.length() - 1); //去掉最后的/r
        Serial.println("content_len=" + String(content_len));
        Serial.println("str_len=" + String(tmp_str.length()));
        ret_str = ret_str + tmp_str;
      }

    }
    delay(10);
  }

  return ret_str;
}


void free_http()
{
  String ret;
  ret = send_at2("AT+HTTPCLOSE=0", "OK", "ERROR" , 5);
  Serial.println("ret=" + ret);
  Serial.println(">>> 断开http连接  ok ...");

}




void ShowStr( String mystring, int x0, int y0, int font_size, uint8_t * framebuffer )
{
  y0 = y0 + 60;

  if (font_size >= 100)
    write_string( (GFXfont *)&msyh36, (char *) mystring.c_str(), &x0, &y0, framebuffer);
  else
    write_string( (GFXfont *)&msyh16, (char *) mystring.c_str(), &x0, &y0, framebuffer);
}

String Get_softrtc_time(int flag)
{
  if (state_sync_time == false)
    return "";

  DateTime now = rtc.now();
  char buf[50];
  buf[0] = '\0';
  if (flag == 0)
  {
    sprintf(buf, "%02d,%02d,%02d,%02d,%02d,%02d", now.year(), now.month() , now.day(), now.hour(), now.minute(), now.second());
  }
  if (flag == 1)
  {
    sprintf(buf, "%02d:%02d", now.hour(), now.minute());
  }
  else if (flag == 2)
  {
    sprintf(buf, "%02d,%02d,%02d,%02d,%02d", now.year(), now.month() , now.day(), now.hour(), now.minute());

  }
  else if (flag == 3)
  {
    sprintf(buf, "%02d月%02d日%s",  now.month() , now.day(), daysOfTheWeek[now.dayOfTheWeek()]);
  }
  else if (flag == 4)
  {
    sprintf(buf, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  }
  else if (flag == 5)
  {
    sprintf(buf, "%02d-%02d-%02d %02d:%02d", now.year(), now.month() , now.day(), now.hour(), now.minute());
  }
  else if (flag == 6)
  {
    sprintf(buf, "%02d-%02d-%02d %02d:%02d:%02d", now.year(), now.month() , now.day(), now.hour(), now.minute(), now.second());
  }
  return String(buf);
}


//每小时一次
void goto_sleep_test()
{
  Serial.println("goto sleep");

  //如果前次有成功同步时间
  if (state_sync_time)
  {
    DateTime now = rtc.now();
    String now_time = Get_softrtc_time(1);
    Serial.println("now_time:" + now_time);

    //计算本次需要休眠秒数

    Serial.println("计算休眠时间 hour=" + String(now.hour() ) + ",minute=" + String(now.minute() ) + ",second=" + String( now.second()));

    //如果short_time_segment是1，表示每1分钟整唤醒一次,定义的闹钟时间可随意
    //                       5，表示每5分钟整唤醒一次,这时定义的闹钟时间要是5的倍数，否则不会定时响铃
    TIME_TO_SLEEP = (short_time_segment - now.minute() % short_time_segment) * 60;
    TIME_TO_SLEEP = TIME_TO_SLEEP - now.second();

    //休眠时间过短，低于30秒直接视同0
    if (TIME_TO_SLEEP < 30)
      TIME_TO_SLEEP = 60 * short_time_segment + 50;

    //考虑到时钟误差，增加几秒，确保唤醒时间超出约定时间
    //TIME_TO_SLEEP = TIME_TO_SLEEP +10;


    Serial.println("go sleep,wake after " + String(TIME_TO_SLEEP)  + "秒 AT:" + Get_softrtc_time(0));
  }
  //时间未同步，时间无效，1小时后再试
  else
  {
    TIME_TO_SLEEP = 3600 + 10;
    Serial.println("时间未同步， go sleep,wake after " + String(TIME_TO_SLEEP)  + "秒 ");
  }

  stoptime = millis() / 1000;

  //平均35-80秒不等，nbiot同步时间需要时间较长
  Serial.println("wake 用时:" + String(stoptime - starttime) + "秒");

  Serial.flush();

  //It will turn off the power of the entire
  // POWER_EN control and also turn off the blue LED light
  epd_poweroff_all();

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  // ESP进入deepSleep状态
  //最大时间间隔为 4,294,967,295 µs 约合71分钟
  //休眠后，GPIP的高，低状态将失效，无法用GPIO控制开关
  esp_deep_sleep_start();
}

//计算总休眠秒数 到TIME_TO_SLEEP
void cal_waker_seconds()
{
  //如果前次有成功同步时间
  if (state_sync_time)
  {
    DateTime now = rtc.now();
    String now_time = Get_softrtc_time(1);
    Serial.println("now_time:" + now_time);

    //计算本次需要休眠秒数

    Serial.println("计算休眠时间 hour=" + String(now.hour() ) + ",minute=" + String(now.minute() ) + ",second=" + String( now.second()));

    //先计算到 00:00的秒数
    TIME_TO_SLEEP =   ((24 - now.hour()) * 60 -  now.minute() ) * 60;
    TIME_TO_SLEEP = TIME_TO_SLEEP - now.second();

    if (TIME_TO_SLEEP < 30)
      TIME_TO_SLEEP = 24 * 60 * 60 + 50;

    //再加上到 06:00的秒数
    TIME_TO_SLEEP = TIME_TO_SLEEP + 6 * 3600;

    //24小时唤醒平均会少15-20分钟，所以用15分钟当误差
    TIME_TO_SLEEP = TIME_TO_SLEEP + 15 * 60 ;
    Serial.println("go sleep,wake after " + String(TIME_TO_SLEEP)  + "秒 AT:" + Get_softrtc_time(0));

  }
  //时间未同步，时间无效，2小时后再试
  else
  {
    TIME_TO_SLEEP = 3600 * 2 + 10;
    Serial.println("时间未同步， go sleep,wake after " + String(TIME_TO_SLEEP)  + "秒 ");
  }
}


//每天1次,早7点整
void goto_sleep()
{
  Serial.println("goto sleep");

  //计算休眠秒数
  cal_waker_seconds();

  stoptime = millis() / 1000;

  //平均35-80秒不等，nbiot同步时间需要时间较长
  Serial.println("wake 用时:" + String(stoptime - starttime) + "秒");

  Serial.flush();

  //It will turn off the power of the entire
  // POWER_EN control and also turn off the blue LED light
  epd_poweroff_all();

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  // ESP进入deepSleep状态
  //最大时间间隔为 4,294,967,295 µs 约合71分钟
  //休眠后，GPIP的高，低状态将失效，无法用GPIO控制开关
  esp_deep_sleep_start();
}


void setup() {

  starttime = millis() / 1000;

  Serial.begin(115200);
  //                               RX  TX
  mySerial.begin(9600, SERIAL_8N1, 12, 13);

  //00/01/01,00:00:01+32
  DateTime now = DateTime(2000, 01, 01, 00, 00, 00);
  rtc.adjust(now);

  //如果启动后不调用此函数，有可能电流一直保持在在60ma，起不到节能效果
  //此步骤不适合在唤醒后没有显示需求时优化掉
  epd_init();
  // framebuffer = (uint8_t *)heap_caps_malloc(EPD_WIDTH * EPD_HEIGHT / 2, MALLOC_CAP_SPIRAM);
  framebuffer = (uint8_t *)ps_calloc(sizeof(uint8_t), EPD_WIDTH * EPD_HEIGHT / 2);
  if (!framebuffer) {
    Serial.println("alloc memory failed !!!");
    delay(1000);
    while (1);
  }
  memset(framebuffer, 0xFF, EPD_WIDTH * EPD_HEIGHT / 2);


  obweatherManager = new weatherManager();
  obweatherManager->ShowStr = ShowStr; //函数指针

  //建议时间 5秒
  delay(5000);  //等待一会，确保网络连接上
  Serial.println(">>> 开启 nb-iot ...");
  clear_uart(5000);

  //为防意外，n秒后强制复位重启，一般用不到。。。
  //n秒如果任务处理不完，看门狗会让esp32自动重启,防止程序跑死...
  uint32_t wdtTimeout = 3 * 60 * 1000; //设置3分钟 watchdog
  timer = timerBegin(0, 80, true);                  //timer 0, div 80
  timerAttachInterrupt(timer, &resetModule, true);  //attach callback
  timerAlarmWrite(timer, wdtTimeout * 1000 , false); //set time in us
  timerAlarmEnable(timer);                          //enable interrupt

  Serial.println("check_waker_7020");

  //at预处理
  check_waker_7020();

  net_connect_succ = false;

  //  String test_weather = "{\"results\":[{\"location\":{\"id\":\"WX4FBXXFKE4F\",\"name\":\"北京\",\"country\":\"CN\",\"path\":\"北京,北京,中国\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2022-06-17\",\"text_day\":\"小雨\",\"code_day\":\"13\",\"text_night\":\"多云\",\"code_night\":\"4\",\"high\":\"31\",\"low\":\"20\",\"rainfall\":\"5.40\",\"precip\":\"0.98\",\"wind_direction\":\"东南\",\"wind_direction_degree\":\"135\",\"wind_speed\":\"8.4\",\"wind_scale\":\"2\",\"humidity\":\"74\"},{\"date\":\"2022-06-18\",\"text_day\":\"多云\",\"code_day\":\"4\",\"text_night\":\"晴\",\"code_night\":\"1\",\"high\":\"33\",\"low\":\"22\",\"rainfall\":\"0.00\",\"precip\":\"0.00\",\"wind_direction\":\"东北\",\"wind_direction_degree\":\"45\",\"wind_speed\":\"8.4\",\"wind_scale\":\"2\",\"humidity\":\"74\"},{\"date\":\"2022-06-19\",\"text_day\":\"晴\",\"code_day\":\"0\",\"text_night\":\"晴\",\"code_night\":\"1\",\"high\":\"34\",\"low\":\"22\",\"rainfall\":\"0.00\",\"precip\":\"0.00\",\"wind_direction\":\"东南\",\"wind_direction_degree\":\"135\",\"wind_speed\":\"3.0\",\"wind_scale\":\"1\",\"humidity\":\"77\"}],\"last_update\":\"2022-06-17T08:00:00+08:00\"}]}";
  //Serial.println("draw_weather:" + test_weather);
  //obweatherManager->draw_weather(test_weather);

  Serial.println("setup");
}


void loop() {

  //3次失败检测网络连接
  if (cnt_check_net >= 3)
    goto_sleep();


  //3次失败获取天气
  if (cnt_sync_weather >= 3)
    goto_sleep();

  //天气已同步
  if (state_sync_weather)
    goto_sleep();

  //上电已超过 2分钟
  //实测70秒足够
  stoptime = millis() / 1000;
  if (stoptime - starttime >= 2 * 60)
    goto_sleep();

  //如果setup时网络连接失败，重新再试
  if (net_connect_succ == false)
  {
    delay(5000);
    Serial.println(">>> 检查网络连接 ...");
    net_connect_succ = connect_nb();
    return;
  }

  if (state_sync_weather == false)
  {
    delay(5000);
    state_sync_weather = get_weather();

    if (state_sync_weather)
    {
      //返回数据长度检查,至少100字节
      if (weather_data_table.length() > 100)
      {
        String g_ink_showtxt = weather_data_table;
        Serial.println("draw_weather:" + g_ink_showtxt);
        cal_waker_seconds();
        stoptime = millis() / 1000;
        String memo1 = "waker after " + String(TIME_TO_SLEEP) + "秒";
        String memo2 = Get_softrtc_time(2) +  " - " + String(stoptime - starttime) + "秒";
        obweatherManager->draw_weather(g_ink_showtxt, memo1, memo2);
        cnt_sync_weather = 0;
      }
      else
        state_sync_weather = false;
    }
    return;
  }

  delay(1000);
}
