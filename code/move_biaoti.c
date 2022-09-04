#include<stdio.h>
#include"mysql.h"
#include"move_biaoti.h"

//“智能多媒体播放器 ”的流水显示
void *move_biaoti()
{

	int k=0,flag_a=0,flag_b=0,flag_c=0,flag_d=0,flag_e=0,flag_f=0,flag_g=0,flag_h=0;
	int a=730,b=730,c=730,d=730,e=730,f=730,g=730,h=730;
	while(1)
	{
		//"智能多媒体播放器 "
			if(k==32*0)
				flag_a = 1;
			if(k==32*1)
				flag_b = 1;
			if(k==32*2)
				flag_c = 1;
			if(k==32*3)
				flag_d = 1;
			if(k==32*4)
				flag_e = 1;
			if(k==32*5)
				flag_f = 1;
			if(k==32*6)
				flag_g = 1;
			if(k==32*7)
				flag_h = 1;
			if(flag_a==1)
			{
				lcd_draw_word(move[0],sizeof(move[0]),32,RED,a,110);
				a--;
			}
			if(flag_b==1)
			{
				lcd_draw_word(move[1],sizeof(move[1]),32,RED,b,110);
				b--;
			}
			if(flag_c==1)
			{
				lcd_draw_word(move[2],sizeof(move[2]),32,RED,c,110);
				c--;
			}
			if(flag_d==1)
			{
				lcd_draw_word(move[3],sizeof(move[3]),32,RED,d,110);
				d--;
			}
			if(flag_e==1)
			{
				lcd_draw_word(move[4],sizeof(move[4]),32,RED,e,110);
				e--;
			}
			if(flag_f==1)
			{
				lcd_draw_word(move[5],sizeof(move[5]),32,RED,f,110);
				f--;
			}
			if(flag_g==1)
			{
				lcd_draw_word(move[6],sizeof(move[6]),32,RED,g,110);
				g--;
			}
			if(flag_h==1)
			{
				lcd_draw_word(move[7],sizeof(move[7]),32,RED,h,110);
				h--;
			}
		k++;
		usleep(7000);
		//bug2已解决，问题所在是fd指针没有初始化复位，加了init1函数后正常
		lcd_draw_rectangle(350,105,420,55,YELLOW);//bug2 使用后同样是段错误，而不使用程序可以运行，但是同理不会刷新文字显示的地方，导致造成一条框都是同一个颜色，从而没有文字显示
		if(a==350)
			a=730;
		if(b==350)
			b=730;
		if(c==350)
			c=730;
		if(d==350)
			d=730;
		if(e==350)
			e=730;
		if(f==350)
			f=730;
		if(g==350)
			g=730;
		if(h==350)
			h=730;
	}
	
}
