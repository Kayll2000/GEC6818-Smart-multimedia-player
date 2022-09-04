#include<stdio.h>
#include"mysql.h"
#include"loading.h"

void loading()//页面加载函数 
{
	
	show_bmp(0,0,bmp_loading[0]);
	usleep(1000000);//1秒
	show_bmp(0,0,bmp_loading[1]);
	usleep(600000);//0.6秒
	show_bmp(0,0,bmp_loading[2]);
	usleep(800000);	//0.8秒
	show_bmp(0,0,bmp_loading[3]);
	usleep(800000);//0.8秒
	show_bmp(0,0,bmp_loading[3]);
	usleep(1500000);//1.5秒
		show_bmp(0,0,bmp_loading[4]);
	usleep(1500000);//1.5秒

	
}
