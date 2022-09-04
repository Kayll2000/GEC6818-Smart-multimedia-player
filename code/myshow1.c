#include<stdio.h>
#include"mysql.h"
#include"myshow1.h"

void *myshow1()//全屏播放
{			pthread_cancel(t1);
			pthread_cancel(t2);
			pthread_cancel(t3);
			show_bmp(1,1,"/project/bmp/10.bmp");
			usleep(1000000);
			show_bmp(1,1,"/project/bmp/11.bmp");
			usleep(1000000);
			show_bmp(1,1,"/project/bmp/12.bmp");
			usleep(1000000);
			show_bmp(1,1,"/project/bmp/13.bmp");
			usleep(1000000);
			show_bmp(1,1,"/project/bmp/14.bmp");
			usleep(1000000);
			show_bmp(1,1,"/project/bmp/10.bmp");
			usleep(1000000);
			clear_lcd(0xffffff);
			myshow();
			mydraw();
			
			myid();
		pthread_create(&t1, NULL, show_time, NULL);//开启显示时间线程
		pthread_create(&t2, NULL, move_biaoti, NULL);//开启标题移动线程
		pthread_create(&t4, NULL, mytouch, NULL);//开启触摸线程
		pthread_create(&t3, NULL, mymoveball, NULL);//开启小球滚动线程
		
	
}
