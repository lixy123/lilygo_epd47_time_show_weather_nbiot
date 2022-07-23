# lilygo_epd47_time_show_weather_nbiot
<b>一.功能：</b> <br/>
1.lilygo 4.7寸墨水屏每日1次通过互联网获取并显示天气, <br/> 
2.待机状态低能耗约0.24ma.  每天唤醒1次，电流约70ma, 一般80秒后进入休眠待机状态， 18650电池供电理论预期应在3-5个月<br/>
3.本代码是 https://github.com//lilygo_epd47_time_show_weather 的扩展版本，用于墨水屏扩展连接wifi上网不方便的场景,
  不用局限于放在wifi路由器附近.  规避了esp32连接wifi偶尔会连接不上的稳定性问题.<br/>
   
<b>二.硬件</b>  <br/>
(一).NBIOT用sim7020c <br/>
1.lilygo-epd47 4.7寸墨水屏 + 锂电池 <br/>
2.2.0mm转2.54mm杜邦线10cm 4线 <br/>
3.sim7020c 开发板 <br/>
ESP32  sim7020c (接线)<br/>
3.3V   VBAT<br/>
GND    GND<br/>
12     TXD<br/>
13     RXD<br/>
<img src= 'https://github.com//lilygo_epd47_time_show_weather_nbiot/blob/main/1.jpg?raw=true' /> <br/>
<img src= 'https://github.com//lilygo_epd47_time_show_weather_nbiot/blob/main/5.jpg?raw=true' /> <br/>

(二).NBIOT用 <br/>
1.lilygo-epd47 4.7寸墨水屏 + 锂电池 <br/>
2.2.0mm转2.54mm杜邦线10cm 4线 <br/>
3. 开发板 <br/>
ESP32 --qs100 (接线)<br/>
3.3V 3.3V<br/>
GND GND<br/>
12 TXD<br/>
13 RXD<br/>

<b>三.代码:</b><br/>
根据所用NBIOT模块不同选择不同目录下的程序:<br/>
1.epd47_sim7020_timer_weather<br/>
nbiot用sim7020c<br/>
2.epd47_qs100_timer_weather<br/>
nbiot用qs100<br/>

烧录到ESP32开发板<br/>
A.软件: arduino 1.8.19<br/>
B.用到库文件:<br/>
https://github.com/espressif/arduino-esp32 版本:1.0.6<br/>
https://github.com/bblanchon/ArduinoJson 版本: 6<br/>
https://github.com/adafruit/RTClib RTClib <br/>
https://github.com/Xinyuan-LilyGO/LilyGo-EPD47 墨水屏驱动库<br/>
C.开发板选择：TTGO-T-WATCH 参数选默认 (字库文件较大，仅用到其分区定义)<br/>
注： 较新的arduino版本才有这个开发板定义: TTGO T-Watch<br/>
参考：https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library<br/>
D.选择端口，点击烧录<br/>
