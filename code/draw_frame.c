#include<stdio.h>
#include"mysql.h"
#include"draw_frame.h"

void lcd_draw_frame(unsigned int x,unsigned int y,unsigned int len_x,unsigned int len_y,unsigned int color)
{
	lcd_draw_hline(x,y,len_x,1,	color);
	lcd_draw_hline(x,y,len_y,0,color);
	lcd_draw_hline(x,y+len_y,len_x,1,color);
	lcd_draw_hline(x+len_x,y,len_y,0,color);
	

}
