#include<stdio.h>
#include"mysql.h"
#include"move_ball.h"

/*
	球运动：碰壁反弹
*/
void move_ball(int x0 ,int y0, int r,int color)
{
	while(1)
	{
		if(x0-r < 250)    //左边界限    //bug 源代码if(x0-r == 250)  -->点击全屏播放三次之后球会突破界限从右往左运行
			x_falg = 0;
		if(x0+r > 330)
			x_falg = 1;
			
		if(x_falg == 0)
			x0++;
		if(x_falg == 1)
			x0--;
		
		if(y0-r < 110)    //左边界限
			y_falg = 0;
		if(y0+r > 180)
			y_falg = 1;
			
		if(y_falg == 0)
			y0++;
		if(y_falg == 1)
			y0--;
	
		draw_ball(x0,y0, r,color);
		usleep(2000);
	}
}
