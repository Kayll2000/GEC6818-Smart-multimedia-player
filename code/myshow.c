#include<stdio.h>
#include"mysql.h"
#include"myshow.h"

void myshow()//我的显示图片函数
{
	draw_ball(500,350,30,mycolor1);//切换上一张照片
	draw_ball(300,350,30,mycolor2);//切换下一张照片
	draw_ball(300,240,50,BLUE);//播放五张全屏照片
	draw_ball(753,220,30,YELLOW);//播放视频
	
	draw_ball(425,220,30,mycolor);//播放音乐
	draw_ball(600,220,30,BLUE);//停止播放音乐
	draw_ball(520,220,30,mycolor3);//切换上一首音乐
	draw_ball(466,280,30,mycolor4);//切换下一首音乐
	
	
	show_bmp(0,0,bmp_name[0]);//画主logo
	show_bmp(0,95,bmp_photo1[0]);//logo1
	show_bmp(0,191,bmp_photo1[1]);//logo2
	show_bmp(0,287,bmp_photo1[2]);//logo3
	show_bmp(0,383,bmp_photo1[3]);//logo3
	
	show_bmp(603,259,bmp_name[3]);
	
	

}
