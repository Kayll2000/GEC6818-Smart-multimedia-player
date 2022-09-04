#include<stdio.h>
#include"mysql.h"
#include"myvideo.h"

void *myvideo()//视频播放函数
{
			pthread_cancel(t1);
			pthread_cancel(t2);
			pthread_cancel(t3);
			pthread_cancel(t4);		
			system("killall -KILL madplay");//如果目前正在播放音乐，先关闭音乐播放
			system("mplayer /project/avi/3.avi -zoom -x 800 -y 480 ");//播放视频--全屏播放
		  //system("mplayer /project/avi/3.avi");//播放视频--原视频分辨率播放
			
			system("killall  -KILL mplayer");//播放完该视频后，关闭视频
			//进行初始化恢复原界面
				init();	
				init1();
				clear_lcd(0xffffff);
				myshow();
				mydraw();
				myid();
			
		pthread_create(&t1, NULL, show_time, NULL);//开启显示时间线程
		pthread_create(&t2, NULL, move_biaoti, NULL);//开启标题移动线程
		pthread_create(&t4, NULL, mytouch, NULL);//开启触摸线程
		pthread_create(&t3, NULL, mymoveball, NULL);//开启小球滚动线程
		
}
