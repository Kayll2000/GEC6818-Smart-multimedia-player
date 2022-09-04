#include<stdio.h>
#include"mysql.h"
#include"draw_hline.h"

void lcd_draw_hline(unsigned int x,unsigned int y,unsigned int len,unsigned int direction,unsigned int color)
{
	unsigned int i=0;
	if(direction==1)
	{
		for(i=0;i<len;i++)
		{
			lcd_draw_point(x+i,y,color);		
		}
	}
	else if(direction==0)
	{
		for(i=0;i<len;i++)
		{
			lcd_draw_point(x,y+i,color);		
		}
	}
	
}
