#include<stdio.h>
#include"mysql.h"
#include"draw_word.h"
/*
ch：文字的点阵数组
len: 数组的长度
w: 文字的宽度
color: 文字的颜色
x,y: 显示的起始点的横纵坐标
*/
void lcd_draw_word(char *ch, int len, int w, int color, int x0, int y0)
{
	int i,j;
	int x, y;
	int flag = w/8; //为什么要除以8？
	//遍历整个点阵数组
	for (i = 0; i < len; i++)
	{
		for (j = 7; j >= 0; j--)
		{
			//if (ch[i] & (0x80/pow(2,7-j)))
			if ((ch[i] >> j) & 1)
			{
				x = 7-j+8*(i%flag) + x0;
				y = i/flag + y0;
				lcd_draw_point(x, y, color);
			}
		}
	}
}
