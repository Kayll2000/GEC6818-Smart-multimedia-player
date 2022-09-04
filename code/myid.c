#include<stdio.h>
#include"mysql.h"
#include"myid.h"

void myid()//显示代号和编号
{
			//代号一
		lcd_draw_word(id1[0], sizeof(id1[0]),16 ,BLUE, 100, 150);
		lcd_draw_word(id1[1], sizeof(id1[1]),16 ,BLUE, 115, 150);
		lcd_draw_word(id1[2], sizeof(id1[2]),16 ,BLUE, 133, 150);
			//代号二
		lcd_draw_word(id2[0], sizeof(id2[0]),16 ,BLUE, 100, 250);
		lcd_draw_word(id2[1], sizeof(id2[1]),16 ,BLUE, 115, 250);
		lcd_draw_word(id2[2], sizeof(id2[2]),16 ,BLUE, 133, 250);
			//代号三
		lcd_draw_word(id3[0], sizeof(id3[0]),16 ,BLUE, 100, 340);
		lcd_draw_word(id3[1], sizeof(id3[1]),16 ,BLUE, 115, 340);
		lcd_draw_word(id3[2], sizeof(id3[2]),16 ,BLUE, 133, 340);
			//代号四
		lcd_draw_word(id4[0], sizeof(id4[0]),16 ,BLUE, 100, 435);
		lcd_draw_word(id4[1], sizeof(id4[1]),16 ,BLUE, 115, 435);
		lcd_draw_word(id4[2], sizeof(id4[2]),16 ,BLUE, 133, 435);
			//编号
			lcd_draw_digit(0000, 100,100,BLUE);//0000
			lcd_draw_digit(0001, 100,200,BLUE);//0001
			lcd_draw_digit(0010, 100,290,BLUE);//0010
			lcd_draw_digit(0011, 100,385,BLUE);//0011
			
			mysign();//按键标识
}
