#include<stdio.h>
#include"mysql.h"
#include"mydraw.h"

void mydraw()//显示画框函数
{
	
	//lcd_draw_frame(0,0,800,120,BLUE);
	lcd_draw_frame(0,0,799,96,BLUE);
	lcd_draw_frame(0,95,200,96,GREEN);
	lcd_draw_frame(0,191,200,96,YELLOW);
	lcd_draw_frame(0,287,200,96,RED);
	lcd_draw_frame(0,383,200,96,BLACK);
}
