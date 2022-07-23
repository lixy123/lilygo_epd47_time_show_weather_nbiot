const uint32_t w15_width = 70;
const uint32_t w15_height = 60;
const uint8_t w15_data[(70*60)/2] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x34, 0xF6, 0xEF, 0x68, 0xFC, 0x5D, 0xF8, 0xFF, 0x38, 0xD3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x33, 0xC3, 0xAF, 0x33, 0xE4, 0x35, 0x73, 0xDF, 0x33, 0x63, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x33, 0x53, 0x4D, 0x33, 0xD4, 0x35, 0x43, 0x5D, 0x33, 0xD3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x38, 0x33, 0x33, 0x33, 0xFA, 0x3C, 0x33, 0x33, 0x33, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D, 0x33, 0x33, 0x53, 0xFF, 0x7F, 0x33, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x44, 0x34, 0x33, 0x33, 0xD4, 0xFF, 0xEF, 0x33, 0x33, 0x33, 0x44, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D, 0x33, 0x33, 0x33, 0x33, 0xF6, 0xFF, 0xFF, 0x39, 0x33, 0x33, 0x33, 0x33, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0x33, 0x33, 0x33, 0x33, 0xF5, 0xFF, 0xFF, 0x36, 0x33, 0x33, 0x33, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCE, 0x88, 0x88, 0x59, 0x33, 0x93, 0xFF, 0xBF, 0x33, 0x43, 0x89, 0x88, 0xC9, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5E, 0x73, 0xFF, 0xFF, 0xEF, 0x34, 0x43, 0xFE, 0x4E, 0x33, 0xE4, 0xFF, 0xFF, 0x7F, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x39, 0x33, 0xFA, 0xFF, 0xFF, 0x3B, 0x33, 0xF7, 0x39, 0x33, 0xF9, 0xFF, 0xFF, 0x3C, 0x33, 0xF9, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D, 0x33, 0xF4, 0xFF, 0xFF, 0x5E, 0x33, 0x94, 0x33, 0x43, 0xFF, 0xFF, 0xFF, 0x34, 0x33, 0xFE, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x33, 0x83, 0xFF, 0xFF, 0xDF, 0x33, 0x33, 0x33, 0xC4, 0xFF, 0xFF, 0xAF, 0x33, 0x93, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDD, 0xBD, 0x34, 0x43, 0xDB, 0xDD, 0xDD, 0x35, 0x33, 0x33, 0xE4, 0xDD, 0xDD, 0x3C, 0x33, 0xD3, 0xDD, 0xFD, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x83, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x43, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x44, 0x44, 0x33, 0x33, 0x43, 0x44, 0x44, 0x33, 0x33, 0x33, 0x43, 0x44, 0x44, 0x34, 0x33, 0x43, 0x44, 0xB4, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEE, 0xCE, 0x34, 0x43, 0xEC, 0xEE, 0xDE, 0x35, 0x33, 0x33, 0xE4, 0xEE, 0xEE, 0x4D, 0x33, 0xD3, 0xEE, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x33, 0xA3, 0xFF, 0xFF, 0xCF, 0x33, 0x33, 0x33, 0xB3, 0xFF, 0xFF, 0xCF, 0x33, 0x63, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3C, 0x33, 0xE5, 0xFF, 0xFF, 0x4E, 0x33, 0xB4, 0x34, 0x43, 0xFE, 0xFF, 0xFF, 0x35, 0x33, 0xFD, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3A, 0x33, 0xFC, 0xFF, 0xFF, 0x39, 0x33, 0xF8, 0x3A, 0x33, 0xF7, 0xFF, 0xFF, 0x3E, 0x33, 0xFA, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0xA4, 0xFF, 0xFF, 0xDF, 0x34, 0x43, 0xFE, 0x5F, 0x33, 0xD3, 0xFF, 0xFF, 0xAF, 0x64, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x77, 0x77, 0x58, 0x33, 0xB3, 0xFF, 0xCF, 0x33, 0x43, 0x78, 0x77, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x33, 0x33, 0x33, 0x33, 0xF6, 0xFF, 0xFF, 0x37, 0x33, 0x33, 0x33, 0x33, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x33, 0x33, 0x33, 0x33, 0xF6, 0xFF, 0xFF, 0x38, 0x33, 0x33, 0x33, 0x33, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xBF, 0x65, 0x45, 0x33, 0x33, 0xC3, 0xFF, 0xDF, 0x33, 0x33, 0x33, 0x56, 0xA6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x45, 0xFB, 0xFF, 0x7A, 0xFE, 0x8D, 0xFB, 0xFF, 0x49, 0xE6, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x33, 0x33, 0x53, 0xFF, 0x5F, 0x33, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x6F, 0x33, 0xE3, 0x9F, 0x33, 0xD6, 0x34, 0xB3, 0xDF, 0x33, 0xA3, 0xFF, 0xFF, 0xFF, 0xFF, 0x37, 0x33, 0x34, 0x33, 0xF9, 0x3A, 0x33, 0x34, 0x33, 0xF5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x33, 0x73, 0x4E, 0x33, 0xD4, 0x34, 0x43, 0x5E, 0x33, 0xC3, 0xFF, 0xFF, 0xFF, 0xBF, 0x33, 0x63, 0x4E, 0x33, 0xD4, 0x34, 0x43, 0x7E, 0x33, 0xB3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x35, 0x33, 0x34, 0x33, 0xFB, 0x38, 0x33, 0x34, 0x33, 0xF7, 0xFF, 0xFF, 0xFF, 0x9F, 0x33, 0xD3, 0xBF, 0x33, 0xD5, 0x35, 0xA3, 0xEF, 0x33, 0x73, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0x33, 0x33, 0x53, 0xFF, 0x4F, 0x33, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0xFF, 0xEF, 0x46, 0xFA, 0xFF, 0x8B, 0xFD, 0x7E, 0xFB, 0xFF, 0x4B, 0xE5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xAF, 0x56, 0x36, 0x33, 0x33, 0xD3, 0xFF, 0xBF, 0x33, 0x33, 0x43, 0x66, 0xC5, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x3E, 0x33, 0x33, 0x33, 0x33, 0xF9, 0xFF, 0xFF, 0x36, 0x33, 0x33, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x3E, 0x33, 0x33, 0x33, 0x33, 0xF8, 0xFF, 0xFF, 0x35, 0x33, 0x33, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xBF, 0x77, 0x77, 0x48, 0x33, 0xD3, 0xFF, 0xAF, 0x33, 0x53, 0x78, 0x77, 0xD7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0xA4, 0xFF, 0xFF, 0xDF, 0x33, 0x53, 0xFF, 0x4E, 0x33, 0xD4, 0xFF, 0xFF, 0x9F, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x3A, 0x33, 0xFE, 0xFF, 0xFF, 0x36, 0x33, 0xFB, 0x37, 0x33, 0xFA, 0xFF, 0xFF, 0x3B, 0x33, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x3C, 0x33, 0xF5, 0xFF, 0xFF, 0x4E, 0x33, 0xB4, 0x34, 0x53, 0xFF, 0xFF, 0xEF, 0x35, 0x43, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x6F, 0x33, 0xC3, 0xFF, 0xFF, 0xAF, 0x33, 0x33, 0x33, 0xC3, 0xFF, 0xFF, 0x9F, 0x33, 0x93, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xEE, 0xCE, 0x33, 0x43, 0xED, 0xEE, 0xEE, 0x34, 0x33, 0x33, 0xD5, 0xEE, 0xEE, 0x4C, 0x33, 0xC4, 0xEE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xBF, 0x44, 0x44, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x43, 0x44, 0x44, 0x33, 0x33, 0x43, 0x44, 0xB4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0x4F, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x53, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0x8F, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x93, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xDD, 0xCD, 0x33, 0x43, 0xDC, 0xDD, 0xED, 0x34, 0x33, 0x33, 0xD6, 0xDD, 0xDD, 0x4B, 0x33, 0xB4, 0xDD, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x9F, 0x33, 0xB3, 0xFF, 0xFF, 0xCF, 0x33, 0x33, 0x33, 0xE3, 0xFF, 0xFF, 0x7F, 0x33, 0xB3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x3D, 0x33, 0xF4, 0xFF, 0xFF, 0x4F, 0x33, 0x94, 0x34, 0x63, 0xFF, 0xFF, 0xEF, 0x34, 0x43, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x39, 0x33, 0xFD, 0xFF, 0xFF, 0x38, 0x33, 0xFA, 0x36, 0x33, 0xFB, 0xFF, 0xFF, 0x3A, 0x33, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x4F, 0x73, 0xFF, 0xFF, 0xEF, 0x34, 0x43, 0xFE, 0x4E, 0x33, 0xE4, 0xFF, 0xFF, 0x6F, 0x53, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xCE, 0x88, 0x88, 0x48, 0x33, 0xC3, 0xFF, 0x8F, 0x33, 0x53, 0x89, 0x88, 0xD8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x4F, 0x33, 0x33, 0x33, 0x33, 0xF6, 0xFF, 0xFF, 0x34, 0x33, 0x33, 0x33, 0x53, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x3E, 0x33, 0x33, 0x33, 0x33, 0xFA, 0xFF, 0xFF, 0x36, 0x33, 0x33, 0x33, 0x43, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x7F, 0x44, 0x34, 0x33, 0x33, 0xE3, 0xFF, 0xCF, 0x34, 0x33, 0x33, 0x44, 0xA4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0x33, 0x33, 0x73, 0xFF, 0x5F, 0x33, 0x33, 0x43, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x36, 0x33, 0x34, 0x33, 0xFC, 0x3A, 0x33, 0x33, 0x33, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x33, 0x63, 0x3D, 0x33, 0xD5, 0x34, 0x43, 0x5D, 0x33, 0xD4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0x33, 0xE3, 0x7F, 0x33, 0xE5, 0x34, 0xA3, 0xBF, 0x33, 0x93, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x33, 0xF9, 0xFF, 0x57, 0xFD, 0x6B, 0xF8, 0xFF, 0x36, 0xD4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	};
