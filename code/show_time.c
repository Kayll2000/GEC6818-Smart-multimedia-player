#include<stdio.h>
#include"mysql.h"
#include"show_time.h"

//屏幕显示时间
void *show_time()
{
	time_t t;
	struct tm *lt;
	char * time_string = NULL;
	int number;
	char a[20];
	char b[20];
	char c[20];
	char date[20]; //时分秒
	char e[20];
	char *p = NULL;
	while(1)
	{
	//获取自1970年至今的时钟指针
		time(&t); //t = time()
		time(&t); 
		//转化为本地时间
		lt = localtime(&t);
		lt = localtime(&t);
		//将时间结构体转化为字符串
		time_string = asctime(lt);
		//printf("time_string  = %s\n",time_string);
		
		sscanf(time_string,"%s %s %s %s %s",a,b,c,date,e);
		//printf("t = %s\n",date);
		p = date;
		int i = 0;
		//显示时分秒
		for(i = 0; i < 8;i++)//it->tim_hour/10;
		
		{
			//sprintf(picpath,"/time/%s",bmp_name);
			switch(*(p+i)) // *(p+i) ==  p[i]
			{
				case  '0': number=0;break;
				case  '1': number=1;break;
				case  '2': number=2;break;
				case  '3': number=3;break;
				case  '4': number=4;break;
				case  '5': number=5;break;
				case  '6': number=6;break;
				case  '7': number=7;break;
				case  '8': number=8;break;
				case  '9': number=9;break;
				case  ':': number=10;break;	
			}
			//显示到居中位置	
			lcd_draw_word(num[number], sizeof(num[number]), 16, BLUE,250+18*i,450);
		}
		//////////////////////////////////////////
		//显示日
			
			int day,o,q;
			day = (lt->tm_mday)+24;//默认2012年1月1日
			o = day/10;	//十位
			q = day%10;	//个位
		
			lcd_draw_word(num[o], sizeof(num[o]), 16, BLUE,660,450);
			lcd_draw_word(num[q], sizeof(num[q]), 16, BLUE,680,450);
			lcd_draw_word(date_arr[2],sizeof(date_arr[2]),24,RED,700,450);
		//显示月
			
			int month,g,h;
			month = (lt->tm_mon)+4;//+7默认是一月
			g = month/10;	//十位
			h = month%10;	//个位
			lcd_draw_word(date_arr[0],sizeof(date_arr[0]),24,RED,573,450);
			lcd_draw_word(date_arr[1],sizeof(date_arr[1]),24,RED,633,450);
			lcd_draw_word(num[g], sizeof(num[g]), 16, BLUE,600,450);
			lcd_draw_word(num[h], sizeof(num[h]), 16, BLUE,620,450);
		//显示年

			int year,l,d,j,f;
			year = (lt->tm_year)+1900+7;//+6//默认2012年
			l = year/1000;	//千位
			d = year/100%10;//百位
			j = year/10%10;	//十位
			f = year%10;	//个位
			lcd_draw_word(num[l], sizeof(num[l]), 16, BLUE,500,450);
			lcd_draw_word(num[d], sizeof(num[d]), 16, BLUE,520,450);
			lcd_draw_word(num[j], sizeof(num[j]), 16, BLUE,540,450);
			lcd_draw_word(num[f], sizeof(num[f]), 16, BLUE,560,450);
		/////////////////////////////////////////////	
			sleep(1);
			//bug1已解决，问题所在是fd指针没有初始化复位，加了init1函数后正常
			lcd_draw_rectangle(240,450,300,25,WHITE);//bug1 刷新数字，如果不使用，后一个数字出来时前一个数字不会消失，会直接覆盖；如果使用红就会有段错误
	}
			
}
