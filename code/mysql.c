#include"mysql.h"

int lcd_fd;
int *lcd;
int time0 = 0;
int count = 0;
int *p;
pthread_t t1,t2,t3,t4,t5,t6,t7,t7,t8,t9;
int ts_fd;
int x_falg = 0;//碰到左半边 0 碰到右半边 1
int y_falg = 0;
int myflag = 0;
int g = 8;
int q = 0;//第几首音乐
int fd;
int *plcd = NULL;
int pthread_flag = 0;
int touch_flag = 0; 

/*
*数组定义区域
*/
char mp3play[4][50]={
	"madplay /project/mp3/1.mp3 &",
	"madplay /project/mp3/2.mp3 &",
	"madplay /project/mp3/3.mp3 &",
	"madplay /project/mp3/4.mp3 &",
	
};
//按键标识
char music[12][72] = {
	/*--  文字:  播  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x03,0xE0,0x1E,0x7F,0xF0,0x1D,
0xFF,0x00,0x1C,0xEF,0xE0,0x1F,0xFF,0xE0,0xFF,0xFF,0xF0,0x1D,0xFF,0xF8,0x1C,0x3F,
0x80,0x1F,0xFF,0xE0,0x1F,0xEC,0xF8,0xFD,0xFF,0xF0,0xFF,0xEE,0xE0,0x7C,0xEE,0xE0,
0x1C,0xFF,0xE0,0x1C,0xEE,0xE0,0x1C,0xEE,0xE0,0xFC,0xEE,0xE0,0x7C,0xFF,0xE0,0x3C,
0xE0,0xE0,0x00,0xC0,0x00,0x00,0x00,0x00},

/*--  文字:  放  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x1C,0x0F,0x00,0x0E,0x0E,0x00,0x0F,
0x4E,0x00,0x0E,0xFE,0x60,0x7F,0xFC,0xF0,0x1E,0x1F,0xF8,0x1D,0xDD,0xE0,0x1F,0xF9,
0xC0,0x1D,0xF9,0xC0,0x1D,0xFB,0xC0,0x1D,0xFF,0xC0,0x1D,0xDF,0x80,0x1D,0xCF,0x80,
0x19,0xCF,0x00,0x39,0xCF,0x00,0x3F,0xCF,0xC0,0x77,0x9F,0xF0,0x63,0x79,0xF8,0xC0,
0xF0,0x60,0x01,0x80,0x00,0x00,0x00,0x00},

/*--  文字:  音  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xF0,0x00,0x00,0x78,0xC0,0x00,
0x71,0xE0,0x3F,0xFF,0xF0,0x07,0x8F,0x00,0x03,0xCF,0x00,0x01,0xCE,0x60,0x01,0x9C,
0xF0,0xFF,0xFF,0xF8,0x0F,0x07,0x80,0x0F,0xFF,0xC0,0x0F,0x07,0x80,0x0F,0x07,0x80,
0x0F,0xFF,0x80,0x0F,0x07,0x80,0x0F,0x07,0x80,0x0F,0xFF,0x80,0x0F,0x07,0x80,0x0F,
0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  乐  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,
0xFF,0xC0,0x0F,0xFC,0x00,0x1E,0x78,0x00,0x1E,0x78,0x00,0x1E,0x78,0xE0,0x1C,0x78,
0xF0,0x1F,0xFF,0xF0,0x1C,0x78,0x00,0x03,0x7C,0x00,0x03,0xFF,0x00,0x07,0xFB,0x80,
0x0F,0x79,0xE0,0x1E,0x79,0xF0,0x3C,0x78,0xF0,0x73,0xF8,0xF0,0xE1,0xF8,0x60,0x00,
0x70,0x00,0x00,0x40,0x00,0x00,0x00,0x00},

/*--  文字:  上  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x78,0x00,0x00,
0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0xC0,0x00,0x71,0xE0,0x00,0x7F,
0xF0,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,
0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x60,0x00,0x70,0xF0,0x7F,0xFF,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  一  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x00,0x01,0xF0,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  首  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x00,0x07,0xCF,0x80,0x03,
0xCE,0x60,0x01,0xDC,0xF0,0xFF,0xFF,0xF8,0x00,0xF0,0x00,0x0E,0xE3,0x80,0x0F,0xFF,
0xC0,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0F,0xFF,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,
0x0F,0xFF,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0F,0xFF,0x80,0x0E,
0x03,0x80,0x0E,0x03,0x80,0x00,0x00,0x00},

/*--  文字:  下  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0xF0,0xFF,
0xFF,0xF8,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xFC,
0x00,0x00,0xFF,0x00,0x00,0xF7,0xC0,0x00,0xF3,0xC0,0x00,0xF1,0xC0,0x00,0xF1,0xC0,
0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,
0xF0,0x00,0x00,0x40,0x00,0x00,0x00,0x00},

/*--  文字:  一  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x00,0x01,0xF0,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  首  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x00,0x07,0xCF,0x80,0x03,
0xCE,0x60,0x01,0xDC,0xF0,0xFF,0xFF,0xF8,0x00,0xF0,0x00,0x0E,0xE3,0x80,0x0F,0xFF,
0xC0,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0F,0xFF,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,
0x0F,0xFF,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0E,0x03,0x80,0x0F,0xFF,0x80,0x0E,
0x03,0x80,0x0E,0x03,0x80,0x00,0x00,0x00},

/*--  文字:  停  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x3C,0x00,0x1F,0x1C,0x60,0x1E,
0x1C,0xF0,0x1F,0xFF,0xF8,0x3D,0xC3,0x80,0x39,0xFF,0xC0,0x3D,0xE3,0x80,0x79,0xE3,
0x80,0x79,0xFF,0x80,0xFB,0xE3,0xF0,0xBB,0xFF,0xF8,0x3F,0x00,0x78,0x3F,0x01,0xC0,
0x3F,0xFF,0xE0,0x38,0x1C,0x00,0x38,0x1C,0x00,0x38,0x1C,0x00,0x38,0xFC,0x00,0x38,
0x7C,0x00,0x30,0x38,0x00,0x00,0x00,0x00},

/*--  文字:  止  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,
0x78,0x00,0x00,0x78,0x00,0x0E,0x78,0x00,0x0F,0x79,0x80,0x0E,0x7B,0xC0,0x0E,0x7F,
0xE0,0x0E,0x78,0x00,0x0E,0x78,0x00,0x0E,0x78,0x00,0x0E,0x78,0x00,0x0E,0x78,0x00,
0x0E,0x78,0x00,0x0E,0x78,0x00,0x0E,0x78,0x60,0x0E,0x78,0xF0,0xFF,0xFF,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}

};
char video[4][72] = {
	/*--  文字:  播  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x03,0xE0,0x1E,0x7F,0xF0,0x1D,
0xFF,0x00,0x1C,0xEF,0xE0,0x1F,0xFF,0xE0,0xFF,0xFF,0xF0,0x1D,0xFF,0xF8,0x1C,0x3F,
0x80,0x1F,0xFF,0xE0,0x1F,0xEC,0xF8,0xFD,0xFF,0xF0,0xFF,0xEE,0xE0,0x7C,0xEE,0xE0,
0x1C,0xFF,0xE0,0x1C,0xEE,0xE0,0x1C,0xEE,0xE0,0xFC,0xEE,0xE0,0x7C,0xFF,0xE0,0x3C,
0xE0,0xE0,0x00,0xC0,0x00,0x00,0x00,0x00},

/*--  文字:  放  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x1C,0x0F,0x00,0x0E,0x0E,0x00,0x0F,
0x4E,0x00,0x0E,0xFE,0x60,0x7F,0xFC,0xF0,0x1E,0x1F,0xF8,0x1D,0xDD,0xE0,0x1F,0xF9,
0xC0,0x1D,0xF9,0xC0,0x1D,0xFB,0xC0,0x1D,0xFF,0xC0,0x1D,0xDF,0x80,0x1D,0xCF,0x80,
0x19,0xCF,0x00,0x39,0xCF,0x00,0x3F,0xCF,0xC0,0x77,0x9F,0xF0,0x63,0x79,0xF8,0xC0,
0xF0,0x60,0x01,0x80,0x00,0x00,0x00,0x00},

/*--  文字:  视  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0xC0,0x1E,0x70,0xE0,0x0E,
0x7F,0xF0,0x0F,0xFC,0xE0,0x7F,0xFF,0xE0,0x07,0xFE,0xE0,0x07,0x7E,0xE0,0x1E,0x7E,
0xE0,0x1E,0x7E,0xE0,0x1F,0xFE,0xE0,0x3F,0xFF,0xE0,0x7D,0xFF,0xE0,0xFC,0x7F,0xF0,
0xDC,0x7F,0xB0,0x1C,0x3F,0xB0,0x1C,0x3F,0xB0,0x1C,0xF7,0xF8,0x1D,0xE7,0xF8,0x1F,
0xC3,0xF8,0x0A,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  频  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x20,0x3F,0x00,0x70,0x3F,
0x7F,0xF8,0x3F,0xE7,0x00,0x3F,0xFE,0xE0,0x3F,0x3F,0xF0,0x3F,0xF8,0xF0,0xFF,0xFF,
0xF0,0x07,0x3F,0xF0,0x07,0x3F,0xF0,0x3F,0xFF,0xF0,0x3F,0xFF,0xF0,0x3F,0xFF,0xF0,
0x77,0xBF,0xF0,0x67,0xBF,0xE0,0xE7,0x0F,0xC0,0xCE,0x1C,0xE0,0x3C,0x38,0xF0,0x70,
0xF0,0x70,0xC1,0xC0,0x30,0x00,0x00,0x00}
};
char change[4][72] = {
	/*--  文字:  上  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x78,0x00,0x00,
0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0xC0,0x00,0x71,0xE0,0x00,0x7F,
0xF0,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,
0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x60,0x00,0x70,0xF0,0x7F,0xFF,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  一  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x00,0x01,0xF0,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  张  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x38,0x00,0x03,0xB8,0x00,0xFF,
0xB8,0xE0,0x03,0xB9,0xF0,0x03,0xBB,0xC0,0x33,0xBF,0x80,0x3F,0xBE,0x00,0x3B,0xBC,
0x60,0x78,0x38,0xF0,0x73,0xFF,0xF0,0x7F,0xBE,0x00,0x77,0xBE,0x00,0x07,0xBF,0x00,
0x07,0x3F,0x00,0x07,0x3B,0x80,0x07,0x3B,0xC0,0x77,0x3F,0xE0,0x3F,0x7D,0xF8,0x1E,
0x78,0xE0,0x08,0x30,0x00,0x00,0x00,0x00},

/*--  文字:  下  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0xF0,0xFF,
0xFF,0xF8,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xFC,
0x00,0x00,0xFF,0x00,0x00,0xF7,0xC0,0x00,0xF3,0xC0,0x00,0xF1,0xC0,0x00,0xF1,0xC0,
0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,
0xF0,0x00,0x00,0x40,0x00,0x00,0x00,0x00}


};
unsigned char quanping[][21*24] = {
	/*--  文字:  全  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0xF8,0x00,0x00,
0xF8,0x00,0x01,0xFC,0x00,0x01,0xCE,0x00,0x03,0x87,0x80,0x07,0x07,0xC0,0x0E,0x03,
0xF8,0x3C,0x07,0xF0,0x77,0xFF,0x80,0xC0,0x70,0x00,0x00,0x70,0x00,0x00,0x73,0x80,
0x0F,0xFF,0xC0,0x00,0x70,0x00,0x00,0x70,0xC0,0x00,0x70,0xE0,0x3F,0xFF,0xF0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  屏  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0xC0,0x3F,0xFF,0xF0,0x3C,
0x01,0xE0,0x3C,0x01,0xE0,0x3F,0xFF,0xE0,0x3D,0xC3,0xE0,0x3D,0xE7,0x80,0x3C,0xF7,
0x00,0x3C,0x6F,0xE0,0x3F,0xFF,0xE0,0x38,0xE7,0x60,0x38,0xE7,0xF0,0x3F,0xFF,0xF8,
0x38,0xE7,0x00,0x38,0xE7,0x00,0x71,0xE7,0x00,0x71,0xC7,0x00,0x67,0x87,0x00,0xDE,
0x07,0x00,0x00,0x06,0x00,0x00,0x00,0x00},

/*--  文字:  播  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x03,0xE0,0x1E,0x7F,0xF0,0x1D,
0xFF,0x00,0x1C,0xEF,0xE0,0x1F,0xFF,0xE0,0xFF,0xFF,0xF0,0x1D,0xFF,0xF8,0x1C,0x3F,
0x80,0x1F,0xFF,0xE0,0x1F,0xEC,0xF8,0xFD,0xFF,0xF0,0xFF,0xEE,0xE0,0x7C,0xEE,0xE0,
0x1C,0xFF,0xE0,0x1C,0xEE,0xE0,0x1C,0xEE,0xE0,0xFC,0xEE,0xE0,0x7C,0xFF,0xE0,0x3C,
0xE0,0xE0,0x00,0xC0,0x00,0x00,0x00,0x00},

/*--  文字:  放  --*/
/*--  华文中宋16;  此字体下对应的点阵为：宽x高=21x24   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x24  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x1C,0x0F,0x00,0x0E,0x0E,0x00,0x0F,
0x4E,0x00,0x0E,0xFE,0x60,0x7F,0xFC,0xF0,0x1E,0x1F,0xF8,0x1D,0xDD,0xE0,0x1F,0xF9,
0xC0,0x1D,0xF9,0xC0,0x1D,0xFB,0xC0,0x1D,0xFF,0xC0,0x1D,0xDF,0x80,0x1D,0xCF,0x80,
0x19,0xCF,0x00,0x39,0xCF,0x00,0x3F,0xCF,0xC0,0x77,0x9F,0xF0,0x63,0x79,0xF8,0xC0,
0xF0,0x60,0x01,0x80,0x00,0x00,0x00,0x00}
};
unsigned char date_arr[][24*21] ={
{
	/*--  文字0:  年  --*/
/*--  华文彩云16;  此字体下对应的点阵为：宽x高=21x22   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x22  --*/
0x07,0x00,0x00,0x0F,0xC0,0x00,0x1C,0xFF,0xF8,0x18,0x00,0x18,0x38,0x00,0x18,0x30,
0x00,0x18,0x61,0xE3,0xF8,0x63,0xE3,0xF0,0xE7,0x00,0x38,0x7E,0x00,0x38,0x3C,0x00,
0x38,0x19,0xE3,0xF0,0x19,0xE3,0xF8,0x60,0x00,0x18,0x60,0x00,0x18,0x60,0x00,0x18,
0x60,0x00,0x18,0x7F,0xE3,0xF8,0x00,0x63,0x00,0x00,0x77,0x00,0x00,0x3E,0x00,0x00,
0x00,0x00

},
{
	/*--  文字1:  月  --*/
/*--  华文彩云16;  此字体下对应的点阵为：宽x高=21x22   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x22  --*/
0x00,0x00,0x00,0x0F,0xFF,0xE0,0x0E,0x00,0x70,0x1C,0x00,0x30,0x18,0x00,0x30,0x18,
0x00,0x30,0x18,0xFE,0x30,0x18,0x00,0x30,0x18,0x00,0x30,0x18,0x00,0x30,0x18,0xFE,
0x30,0x18,0x00,0x30,0x18,0x00,0x30,0x38,0x00,0x30,0x38,0x1E,0x30,0x30,0xF8,0x30,
0x71,0xF0,0x30,0x61,0xB0,0x30,0x63,0xB0,0x30,0x3F,0x38,0x70,0x1E,0x3F,0xE0,0x00,
0x00,0x00
},
{
	/*--  文字2:  日  --*/
/*--  华文彩云16;  此字体下对应的点阵为：宽x高=21x22   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x22  --*/
0x00,0x00,0x00,0x1F,0xFF,0xC0,0x38,0x00,0xE0,0x70,0x00,0x70,0x70,0x00,0x30,0x70,
0x00,0x30,0x71,0xFE,0x30,0x73,0x86,0x30,0x73,0xFE,0x30,0x70,0x00,0x30,0x70,0x00,
0x30,0x70,0x00,0x30,0x70,0x00,0x30,0x71,0xFE,0x30,0x73,0x86,0x30,0x71,0xFE,0x30,
0x70,0x00,0x30,0x70,0x00,0x70,0x30,0x00,0x70,0x38,0x00,0xE0,0x1F,0xFF,0xC0,0x00,
0x00,0x00
}
};
//开机加载图片
char *bmp_loading[5] = {
	/* 分辨率796*479 */
	"/project/bmp/k0.bmp",
	"/project/bmp/k1.bmp",
	"/project/bmp/k2.bmp",
	"/project/bmp/k3.bmp",
	"/project/bmp/k4.bmp"
	
	
};

//代号
char id1[3][32] = {
	{/*--  文字:  代  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x08,0x90,0x08,0x88,0x08,0x88,0x10,0x80,0x10,0xBE,0x37,0xC0,0x30,0x80,0x50,0x40,
0x90,0x40,0x10,0x40,0x10,0x20,0x10,0x22,0x10,0x12,0x10,0x0A,0x10,0x06,0x10,0x02
},
{
/*--  文字:  号  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0xFF,0xFE,
0x08,0x00,0x10,0x00,0x1F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xA0,0x00,0x40},
{
/*--  文字:  一  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}
};

char id2[3][32] = {
{
/*--  文字:  代  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x08,0x90,0x08,0x88,0x08,0x88,0x10,0x80,0x10,0xBE,0x37,0xC0,0x30,0x80,0x50,0x40,
0x90,0x40,0x10,0x40,0x10,0x20,0x10,0x22,0x10,0x12,0x10,0x0A,0x10,0x06,0x10,0x02},
{
/*--  文字:  号  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0xFF,0xFE,
0x08,0x00,0x10,0x00,0x1F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xA0,0x00,0x40},
{
/*--  文字:  二  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00
}
};

char id3[3][32] = {
{
/*--  文字:  代  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x08,0x90,0x08,0x88,0x08,0x88,0x10,0x80,0x10,0xBE,0x37,0xC0,0x30,0x80,0x50,0x40,
0x90,0x40,0x10,0x40,0x10,0x20,0x10,0x22,0x10,0x12,0x10,0x0A,0x10,0x06,0x10,0x02},
{
/*--  文字:  号  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0xFF,0xFE,
0x08,0x00,0x10,0x00,0x1F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xA0,0x00,0x40},
{
/*--  文字:  三  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00}

};

char id4[3][32] = {
{
/*--  文字:  代  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x08,0x90,0x08,0x88,0x08,0x88,0x10,0x80,0x10,0xBE,0x37,0xC0,0x30,0x80,0x50,0x40,
0x90,0x40,0x10,0x40,0x10,0x20,0x10,0x22,0x10,0x12,0x10,0x0A,0x10,0x06,0x10,0x02},
{
/*--  文字:  号  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0xFF,0xFE,
0x08,0x00,0x10,0x00,0x1F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xA0,0x00,0x40},
{
/*--  文字:  四  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x00,0x00,0x7F,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,
0x48,0x44,0x48,0x3C,0x50,0x04,0x60,0x04,0x40,0x04,0x7F,0xFC,0x40,0x04,0x00,0x00
}
};
//小型logo
char *bmp_photo1[5] = {
	/* 分辨率100*95 */
		"/project/bmp/01.bmp",
		"/project/bmp/02.bmp",
		"/project/bmp/03.bmp",
		"/project/bmp/04.bmp"
		};
//小型照片
char *bmp_name[12] = {
	/* 分辨率200*95*/
		"/project/bmp/0.bmp",
		"/project/bmp/1.bmp",
		"/project/bmp/2.bmp",
		"/project/bmp/3.bmp",
		"/project/bmp/4.bmp",
		"/project/bmp/5.bmp",
		"/project/bmp/6.bmp",
		"/project/bmp/7.bmp",
		"/project/bmp/8.bmp",
		"/project/bmp/9.bmp"
		

	};
char *bmp_photo[9] = {
	/* 分辨率200*95*/
		"/project/bmp/1.bmp",
		"/project/bmp/2.bmp",
		"/project/bmp/3.bmp",
		"/project/bmp/4.bmp",
		"/project/bmp/5.bmp",
		"/project/bmp/6.bmp",
		"/project/bmp/7.bmp",
		"/project/bmp/8.bmp",
		"/project/bmp/9.bmp"

	};
unsigned char move[][32*36]={
{
/*--  文字:  智  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,0xE0,0x30,0x70,0x07,0xC3,0x3C,0x78,
0x07,0x87,0xBF,0xFC,0x07,0xFF,0xFC,0x7C,0x0F,0xF0,0x3C,0x78,0x0E,0xF0,0x3C,0x78,
0x1C,0xF1,0xBC,0x78,0x1C,0xF3,0xFC,0x78,0x7F,0xFF,0xFC,0x78,0x00,0xF0,0x3C,0x78,
0x01,0xFC,0x3C,0x78,0x01,0xFF,0xBF,0xF8,0x03,0xCF,0xFC,0x78,0x03,0xC7,0xFC,0x78,
0x0F,0xE3,0xB3,0xE0,0x1F,0xFF,0xFF,0xE0,0x3D,0xF0,0x03,0xE0,0xF1,0xF0,0x03,0xC0,
0x01,0xF0,0x03,0xC0,0x01,0xF0,0x03,0xC0,0x01,0xFF,0xFF,0xC0,0x01,0xF0,0x03,0xC0,
0x01,0xF0,0x03,0xC0,0x01,0xF0,0x03,0xC0,0x01,0xFF,0xFF,0xC0,0x01,0xF0,0x03,0xC0,
0x01,0xF0,0x03,0xC0,0x01,0xF0,0x03,0xC0,0x01,0xC0,0x03,0x80,0x00,0x00,0x00,0x00},
{
/*--  文字:  能  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0x00,0x01,0xF8,0x7C,0x60,0x01,0xF8,0x78,0xF0,
0x03,0xE0,0x79,0xF8,0x03,0xF8,0x7B,0xF8,0x07,0xBE,0x7F,0xD8,0x0F,0x1F,0x7F,0x18,
0x7F,0xFF,0xFC,0x38,0x7F,0xFF,0xF8,0x38,0x7F,0xE7,0xF8,0x38,0x30,0x0F,0x78,0x7E,
0x1E,0x1E,0x7F,0xFC,0x1F,0xFF,0x7F,0xFC,0x1E,0x1F,0x7F,0xF8,0x1E,0x1E,0x7C,0x00,
0x1E,0x1E,0x78,0x70,0x1F,0xFE,0x78,0xF8,0x1E,0x1E,0x7B,0xF8,0x1E,0x1E,0x7F,0xE0,
0x1E,0x1E,0x7F,0x8C,0x1E,0x1E,0x7E,0x0C,0x1F,0xFE,0x78,0x1C,0x1E,0x1E,0x78,0x1C,
0x1E,0x1E,0x78,0x1E,0x1E,0x1E,0x7C,0x3E,0x1E,0x1E,0x7F,0xFE,0x1E,0xFE,0x7F,0xFE,
0x1E,0x7E,0x7F,0xFC,0x1E,0x3E,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  多  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x07,0x00,0x00,0x00,0x07,0xC0,0x00,0x00,0x0F,0xE0,0x00,0x00,0x1F,0x80,0xE0,
0x00,0x1F,0x01,0xF0,0x00,0x3F,0xFF,0xF8,0x00,0x7C,0x03,0xF8,0x00,0xFE,0x07,0xE0,
0x01,0xFF,0x0F,0xC0,0x03,0xEF,0x9F,0x80,0x07,0x87,0xFE,0x00,0x1E,0x07,0xFC,0x00,
0x18,0x03,0xF8,0x00,0x00,0x0F,0xE0,0x00,0x00,0x7F,0xF8,0x00,0x03,0xFF,0xF8,0x30,
0x3F,0xE3,0xE0,0x78,0x1C,0x07,0xFF,0xFC,0x00,0x1F,0x80,0xFE,0x00,0x3F,0x01,0xF0,
0x00,0x7F,0xC3,0xE0,0x00,0xFB,0xE7,0xC0,0x03,0xE3,0xEF,0x80,0x0F,0x81,0xFF,0x00,
0x1E,0x01,0xFE,0x00,0x00,0x01,0xFC,0x00,0x00,0x0F,0xF0,0x00,0x00,0x7F,0xC0,0x00,
0x1F,0xFE,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  媒  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x01,0x81,0x00,0x03,0xC1,0xF1,0xF0,0x03,0xE1,0xE1,0xE0,0x07,0xC1,0xE1,0xEC,
0x07,0x81,0xE1,0xFE,0x07,0x9F,0xFF,0xFF,0x07,0x81,0xE1,0xE0,0x07,0xBD,0xE1,0xE0,
0x7F,0xFF,0xE1,0xE0,0x07,0x3D,0xFF,0xE0,0x0F,0x7D,0xE1,0xE0,0x0F,0x79,0xE1,0xE0,
0x0F,0x79,0xE1,0xE0,0x0F,0x79,0xE1,0xE0,0x0E,0x79,0xFF,0xE0,0x1E,0x71,0xFF,0xE0,
0x1E,0xF1,0xFD,0x18,0x1E,0xF0,0x3C,0x3C,0x1C,0xFF,0xFF,0xFE,0x1E,0xE0,0xFF,0x00,
0x1F,0xE0,0xFF,0x00,0x03,0xF1,0xFF,0x80,0x03,0xF9,0xFF,0xC0,0x07,0xFF,0xFD,0xE0,
0x07,0x3F,0xBD,0xF0,0x0E,0x1F,0x3C,0xFE,0x1C,0x1E,0x3C,0x7F,0x38,0x3C,0x3C,0x38,
0x70,0x78,0x3C,0x00,0x60,0xE0,0x3C,0x00,0x00,0xC0,0x38,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  体  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0xE0,0x78,0x00,0x03,0xF0,0x7C,0x00,0x03,0xE0,0x78,0x00,
0x03,0xC0,0x78,0x00,0x03,0xC0,0x78,0x78,0x07,0xC0,0x78,0xFC,0x07,0xFF,0xFF,0xFC,
0x07,0x80,0xFC,0x00,0x0F,0x01,0xFC,0x00,0x0F,0xC1,0xFE,0x00,0x0F,0xC1,0xFE,0x00,
0x1F,0x83,0xFF,0x00,0x1F,0x83,0xFF,0x00,0x3F,0x87,0xFF,0x80,0x3F,0x87,0x7B,0x80,
0x77,0x8F,0x7B,0xC0,0x67,0x8E,0x7B,0xE0,0xC7,0x9E,0x79,0xF0,0x07,0x9C,0x7B,0xFC,
0x07,0xB8,0x7F,0xFF,0x07,0xFF,0xFF,0xFE,0x07,0xE0,0x78,0x38,0x07,0xC0,0x78,0x00,
0x07,0x80,0x78,0x00,0x07,0x80,0x78,0x00,0x07,0x80,0x78,0x00,0x07,0x80,0x78,0x00,
0x07,0x80,0x78,0x00,0x07,0x00,0x78,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  播  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x30,0x07,0x80,0x01,0xF0,0x07,0xE0,0x1F,0xF8,0x07,0x87,0xFF,0xFC,
0x07,0x9F,0xFE,0x00,0x07,0x86,0x3C,0xE0,0x07,0xB7,0xBC,0xF0,0x07,0xFB,0xFD,0xF0,
0x7F,0xFF,0xFF,0xDC,0x07,0x81,0xFF,0xBE,0x07,0x9F,0xFF,0xFE,0x07,0x81,0xFF,0x80,
0x07,0x9D,0xFF,0xC0,0x07,0xFB,0xFD,0xF0,0x07,0xE7,0xBC,0xFF,0x1F,0xCF,0x3C,0x7C,
0xFF,0x9F,0x10,0xF8,0x7F,0xBF,0xFF,0xF8,0x7F,0xFF,0x3C,0xF8,0x37,0x8F,0x3C,0xF0,
0x07,0x8F,0x3C,0xF0,0x07,0x8F,0x3C,0xF0,0x07,0x8F,0xFF,0xF0,0x07,0x8F,0x3C,0xF0,
0x07,0x8F,0x3C,0xF0,0x67,0x8F,0x3C,0xF0,0x7F,0x8F,0xFF,0xF0,0x1F,0x8F,0x00,0xF0,
0x0F,0x0F,0x00,0xF0,0x0E,0x0F,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  放  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x07,0x00,0x1C,0x00,0x07,0x80,0x1F,0x00,0x03,0xC0,0x3E,0x00,0x03,0xE0,0x3E,0x00,
0x01,0xE0,0x3C,0x00,0x01,0xE7,0x3C,0x10,0x01,0xCF,0xBC,0x38,0x7F,0xFF,0xFC,0x7E,
0x07,0xC0,0x7F,0xFE,0x07,0xC0,0x79,0xF0,0x07,0x8C,0x71,0xF0,0x07,0x8F,0xF1,0xE0,
0x07,0xFF,0xF1,0xE0,0x07,0x9F,0xF1,0xE0,0x07,0x9F,0xF3,0xE0,0x07,0x9F,0xF3,0xC0,
0x07,0x9F,0xB3,0xC0,0x07,0x9F,0x3B,0xC0,0x07,0x9E,0x3F,0xC0,0x07,0x1E,0x3F,0x80,
0x0F,0x1E,0x1F,0x80,0x0F,0x1E,0x1F,0x00,0x0E,0x1E,0x1F,0x00,0x1E,0x1E,0x1F,0xC0,
0x1F,0xFE,0x3F,0xF0,0x38,0xFC,0x7B,0xFC,0x38,0x78,0xF1,0xFF,0x70,0x73,0xE0,0xFF,
0xE0,0x07,0x80,0x78,0x00,0x1F,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00},
{
/*--  文字:  器  --*/
/*--  华文中宋24;  此字体下对应的点阵为：宽x高=32x36   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1E,0x70,0xE0,0x0F,0xFF,0x7F,0xF8,
0x0F,0x1E,0x7F,0xF0,0x0F,0x1E,0x79,0xF0,0x0F,0x1E,0x79,0xF0,0x0F,0xFE,0x79,0xF0,
0x0F,0xFE,0x7F,0xF0,0x0F,0x1E,0x79,0xF0,0x0E,0x1F,0x98,0xE0,0x00,0x0F,0xFE,0x00,
0x00,0x0F,0x1F,0x38,0x00,0x1F,0x0F,0x7C,0x7F,0xFF,0xFF,0xFE,0x00,0x3C,0x70,0x00,
0x00,0x78,0x3C,0x00,0x00,0xF0,0x1F,0x00,0x03,0xE0,0x0F,0xC0,0x07,0x9E,0xF3,0xFF,
0x1F,0xFF,0xFF,0xFF,0x7F,0x9E,0xFF,0xFC,0xE7,0x9E,0xF1,0xF8,0x07,0x9E,0xF1,0xE0,
0x07,0x9E,0xF1,0xE0,0x07,0xFE,0xF1,0xE0,0x07,0xFE,0xFF,0xE0,0x07,0x9E,0xF1,0xE0,
0x07,0x9E,0xF1,0xE0,0x07,0x1C,0xF1,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}

};
unsigned char num[][16*21]={
	{
/*--  文字:  0  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x3F,0x80,0x39,0xC0,0x71,0xC0,0x70,0xC0,
0x70,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x70,0xC0,0x71,0xC0,0x39,0xC0,
0x3F,0x80,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00

},
{
/*--  文字:  1  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x0E,0x00,0x1E,0x00,0x3E,0x00,0x36,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{
/*--  文字:  2  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x3F,0x80,0x71,0xC0,0x71,0xC0,0x01,0xC0,
0x01,0xC0,0x01,0x80,0x03,0x80,0x07,0x00,0x0E,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,
0x7F,0xC0,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00
},
{
/*--  文字:  3  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x3F,0x80,0x31,0xC0,0x71,0xC0,0x01,0xC0,
0x01,0xC0,0x07,0x80,0x0F,0x80,0x01,0xC0,0x01,0xC0,0x00,0xC0,0x71,0xC0,0x71,0xC0,
0x3F,0x80,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{
/*--  文字:  4  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0x80,0x07,0x80,0x07,0x80,0x0F,0x80,
0x1D,0x80,0x19,0x80,0x39,0x80,0x71,0x80,0x61,0x80,0xFF,0xE0,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00
},
{/*--  文字:  5  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x30,0x00,0x30,0x00,0x70,0x00,
0x7F,0x00,0x7F,0x80,0x61,0xC0,0x01,0xC0,0x00,0xC0,0x00,0xC0,0xE1,0xC0,0x73,0xC0,
0x7F,0x80,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{/*--  文字:  6  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x07,0x00,0x0E,0x00,0x0E,0x00,0x1C,0x00,
0x38,0x00,0x3F,0xC0,0x79,0xC0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x71,0xC0,
0x3F,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{/*--  文字:  7  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x00,0xC0,0x01,0xC0,0x01,0x80,
0x03,0x80,0x03,0x00,0x07,0x00,0x06,0x00,0x0E,0x00,0x0E,0x00,0x0C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{/*--  文字:  8  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x3F,0x80,0x71,0xC0,0x71,0xC0,0x71,0xC0,
0x71,0xC0,0x3F,0x80,0x3F,0x80,0x71,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x71,0xC0,
0x7F,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{/*--  文字:  9  --*/
/*--  楷体16;  此字体下对应的点阵为：宽x高=12x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x3F,0x80,0x73,0xC0,0x71,0xC0,0xE1,0xC0,
0xE1,0xC0,0x61,0xC0,0x73,0xC0,0x3F,0x80,0x07,0x00,0x07,0x00,0x0E,0x00,0x0E,0x00,
0x1C,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
	/*--  文字:  :  --*/
/*--  新宋体16;  此字体下对应的点阵为：宽x高=11x21   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x21  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x1E,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x1E,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}

};
//0~9的模，宽度16
unsigned char w_digit[][58] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC0,0x1E,0xF0,
0x3C,0x78,0x38,0x38,0x78,0x3C,0x78,0x3C,0x70,0x1C,0x70,0x1C,0x70,0x1C,0x70,0x1C,
0x70,0x1C,0x70,0x1C,0x70,0x3C,0x78,0x3C,0x78,0x38,0x38,0x38,0x3C,0x70,0x1E,0xF0,
0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0x80,
0x1F,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0xC0,
0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x1C,0x70,
0x38,0x38,0x78,0x3C,0x78,0x3C,0x78,0x3C,0x38,0x38,0x00,0x78,0x00,0x70,0x00,0xE0,
0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x0C,0x38,0x1C,0x70,0x3C,0x7F,0xF8,
0x7F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x38,0xF0,
0x38,0x78,0x78,0x78,0x38,0x78,0x00,0x78,0x00,0x70,0x00,0xE0,0x07,0xC0,0x00,0xF0,
0x00,0x78,0x00,0x38,0x00,0x3C,0x00,0x3C,0x78,0x3C,0x78,0x38,0x78,0x38,0x38,0xF0,
0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0x01,0xE0,
0x03,0xE0,0x03,0xE0,0x07,0xE0,0x0E,0xE0,0x0C,0xE0,0x1C,0xE0,0x18,0xE0,0x30,0xE0,
0x70,0xE0,0x60,0xE0,0xFF,0xFC,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x01,0xF0,
0x07,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x3F,0xF8,
0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x30,0x00,0x37,0xE0,0x3C,0x70,0x38,0x38,
0x10,0x3C,0x00,0x3C,0x00,0x3C,0x78,0x3C,0x78,0x3C,0x78,0x38,0x38,0x78,0x38,0xF0,
0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x0E,0x78,
0x1C,0x78,0x38,0x78,0x38,0x00,0x78,0x00,0x70,0x00,0x77,0xE0,0x7E,0x78,0x78,0x38,
0x78,0x3C,0x70,0x3C,0x70,0x1C,0x70,0x1C,0x78,0x3C,0x38,0x3C,0x3C,0x38,0x1E,0x70,
0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x3F,0xF8,
0x78,0x38,0x70,0x30,0x60,0x60,0x00,0x60,0x00,0xC0,0x01,0xC0,0x01,0xC0,0x03,0x80,
0x03,0x80,0x03,0x80,0x07,0x80,0x07,0x00,0x07,0x00,0x07,0x00,0x0F,0x00,0x0F,0x00,
0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x3C,0x70,
0x38,0x38,0x70,0x3C,0x70,0x1C,0x70,0x1C,0x38,0x38,0x3E,0x70,0x0F,0xE0,0x1F,0xE0,
0x38,0xF0,0x70,0x78,0x70,0x3C,0x70,0x1C,0x70,0x1C,0x70,0x1C,0x70,0x38,0x3C,0x70,
0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x3C,0x70,
0x38,0x38,0x78,0x38,0x70,0x3C,0x70,0x3C,0x70,0x1C,0x70,0x3C,0x70,0x3C,0x78,0x7C,
0x3C,0xFC,0x1F,0xFC,0x00,0x3C,0x00,0x38,0x00,0x38,0x38,0x70,0x38,0x70,0x3D,0xE0,
0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};