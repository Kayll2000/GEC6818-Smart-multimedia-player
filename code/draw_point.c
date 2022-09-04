#include<stdio.h>
#include"mysql.h"
#include"draw_point.h"
//在坐标为x,y的点显示一个颜色为color的像素点
void lcd_draw_point(int x, int y, int color)
{
	*(lcd + x +800*y) = color;
	
}
