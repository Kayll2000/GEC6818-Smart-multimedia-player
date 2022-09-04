#include<stdio.h>
#include"mysql.h"
#include"draw_rectangle.h"

//画矩形
/*	x,y:横纵坐标
	w:长度
	h:高度
	color：底色的颜色
*/
void lcd_draw_rectangle(int x,int y,int w,int h,int color)
{
	int i,j;
	for(i = x;i<w+x;i++)//行
		for(j = y;j<h+y;j++)//列
			*(plcd + i +800*j) = color;
}
