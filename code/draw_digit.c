#include<stdio.h>
#include"draw_digit.h"
#include"mysql.h"

//在坐标为x0,y0的位置开始显示数字，数字的值为value，显示的颜色为 color
void lcd_draw_digit(int value,int x0, int y0, int color)
{
	//判断是几位数
	int q,b,s,g;
	if (value / 1000)
	{
		q = value/1000;
		lcd_draw_word(w_digit[q],sizeof(w_digit[q]),16,color,x0,y0);
		//lcd_draw_num(q,32,100,100,RED);	
		b = value/100%10;
		lcd_draw_word(w_digit[b],sizeof(w_digit[b]),16,color,x0+20,y0);
		s = value/10%10;
		lcd_draw_word(w_digit[s],sizeof(w_digit[s]),16,color,x0+40,y0);
		g = value%10;
		lcd_draw_word(w_digit[g],sizeof(w_digit[g]),16,color,x0+60,y0);
	}
	else if (value / 100)
	{
		b = value/100;
		lcd_draw_word(w_digit[b],sizeof(w_digit[b]),16,color,x0+20,y0);
		s = value/10%10;
		lcd_draw_word(w_digit[s],sizeof(w_digit[s]),16,color,x0+40,y0);
		g = value%10;
		lcd_draw_word(w_digit[g],sizeof(w_digit[g]),16,color,x0+60,y0);	
	}
	else if (value / 10)
	{
		s = value/10;
		lcd_draw_word(w_digit[s],sizeof(w_digit[s]),16,color,x0+40,y0);
		g = value%10;
		lcd_draw_word(w_digit[g],sizeof(w_digit[g]),16,color,x0+60,y0);
	}
	else 
	{
		lcd_draw_word(w_digit[value],sizeof(w_digit[value]),16,color,x0+60,y0);
	}
}
