#include<stdio.h>
#include"mysql.h"
#include"init.h"

/*
	初始化
*/
void init()//初始化1
{	
	//打开lcd
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
	{
		printf("open lcd fail\n");
		return ;
	}
	//申请映射
	lcd = mmap(NULL,800*480*4,PROT_WRITE|PROT_READ,MAP_SHARED,lcd_fd,0);
	white_back();
	//打开触摸屏
	ts_fd = open("/dev/input/event0",O_RDWR);
	if(ts_fd < 0)
	{
		printf("open ts fail\n");
		return ;
	}
	
	srand((unsigned)time(NULL));//用当前时间，设置种子 
	
}
