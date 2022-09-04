#include<stdio.h>
#include"mysql.h"
#include"clearlcd.h"
/*
	清屏
	color：屏幕颜色
*/
void clear_lcd(int color)
{
	int i;
	for(i = 0;i < FB_W*FB_H;i++)
	{	
		*(lcd+i) = color;
	}
	
}
