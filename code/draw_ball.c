#include<stdio.h>
#include"mysql.h"
#include"draw_ball.h"
/*
	draw_ball:画圆
	x0,y0:圆点坐标
	r	 ：圆半径
	color：颜色
*/
void draw_ball(int x0 ,int y0, int r,int color)
{
	int y,x;
	for(y = y0-r;y <= y0+r;y++)
		for(x = x0-r;x <= x0+r;x++)
		{
			if((y-y0)*(y-y0) + (x-x0)*(x-x0) < r*r)
				*(lcd+x+(y*800)) = color;
			else	
				*(lcd+x+(y*800)) = WHITE;
		}
}
