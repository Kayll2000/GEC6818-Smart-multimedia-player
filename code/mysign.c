#include<stdio.h>
#include"mysql.h"
#include"mysign.h"

void mysign()//按键标识——用户友好界面
{		//全屏播放
		lcd_draw_word(quanping[0], sizeof(quanping[0]),24 ,RED, 230, 210);
		lcd_draw_word(quanping[1], sizeof(quanping[1]),24 ,RED, 230, 230);
		lcd_draw_word(quanping[2], sizeof(quanping[2]),24 ,RED, 230, 250);
		lcd_draw_word(quanping[3], sizeof(quanping[3]),24,RED, 230, 270);
		
		//上一张
		lcd_draw_word(change[0], sizeof(change[0]),24,RED, 480, 380);
		lcd_draw_word(change[1], sizeof(change[1]),24,RED, 500, 380);
		lcd_draw_word(change[2], sizeof(change[2]),24,RED, 520, 380);
		
		//下一张
		lcd_draw_word(change[0], sizeof(change[3]),24,RED, 280, 380);
		lcd_draw_word(change[1], sizeof(change[1]),24,RED, 300, 380);
		lcd_draw_word(change[2], sizeof(change[2]),24,RED, 320, 380);
		
		//播放视频
		lcd_draw_word(video[0], sizeof(video[0]),24,RED, 700, 165);
		lcd_draw_word(video[1], sizeof(video[1]),24,RED, 700, 185);
		lcd_draw_word(video[2], sizeof(video[2]),24,RED, 700, 205);
		lcd_draw_word(video[3], sizeof(video[3]),24,RED, 700, 225);
		
		//播放音乐
		lcd_draw_word(music[0], sizeof(music[0]),24,RED, 385, 168);
		lcd_draw_word(music[1], sizeof(music[1]),24,RED, 405, 168);
		lcd_draw_word(music[2], sizeof(music[2]),24,RED, 425, 168);
		lcd_draw_word(music[3], sizeof(music[3]),24,RED, 445, 168);
		
		//上一首
		lcd_draw_word(music[4], sizeof(music[4]),24,RED, 490, 168);
		lcd_draw_word(music[5], sizeof(music[5]),24,RED, 510, 168);
		lcd_draw_word(music[6], sizeof(music[6]),24,RED, 530, 168);
		
		//下一首
		lcd_draw_word(music[7], sizeof(music[7]),24,RED, 500, 275);
		lcd_draw_word(music[8], sizeof(music[8]),24,RED, 520, 275);
		lcd_draw_word(music[9], sizeof(music[9]),24,RED, 540, 275);
		
		//停止播放
		lcd_draw_word(music[10], sizeof(music[7]),24,RED, 575, 168);
		lcd_draw_word(music[11], sizeof(music[8]),24,RED, 595, 168);
		lcd_draw_word(music[0], sizeof(music[0]),24,RED, 615, 168);
		lcd_draw_word(music[1], sizeof(music[1]),24,RED, 635, 168);
}
