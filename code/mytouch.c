#include<stdio.h>
#include"mysql.h"
#include"mytouch.h"

//执行界面
void *mytouch()
{		int x,y;

			while(1)
	{
	
		get_x_y(&x,&y);

			
		//下一张图片
		if(x > 300 && x < 400 && y > 420 && y < 520)
		{
		
			g++;
			if(g >= 9)
			{
				g = 0;
			
			}

			show_bmp(603,259,bmp_name[1]);
			show_ct_bmp(bmp_photo[g]);
			
		}
		
		//上一张图片
		if(x > 580 && x < 700 && y > 420 && y < 520)
		{
		
			
			g--;
			if(g <= -1)
			{
				g = 8;
			}
			show_bmp(603,259,bmp_name[1]);
			show_ct_bmp(bmp_photo[g]);
		}

		if(x > 350 && x < 450 && y > 290 && y < 390) //五张图片显示全屏
		{
			/*bug3 这里取消线程和后面创建线程可以正常运行，但是两到三次触摸到该点位时，会出现小球突破原有函数设定界限，直接从右往左运行而且每一次
			坐标y值会微微向上改变（即每次y值都会自动减小），然后会刷掉小球划过的logo图片，最后运行到最上方时出现段错误。
			*/
			pthread_cancel(t1);
			pthread_cancel(t2);
			pthread_cancel(t3);
			pthread_cancel(t4);
			pthread_create(&t5, NULL, myshow1, NULL);
			
		}
		if(x > 930 && x < 1022 && y > 250 && y < 305) //视频播放
		{
			pthread_cancel(t1);
			pthread_cancel(t2);
			pthread_cancel(t3);
			pthread_cancel(t4);
			
			pthread_create(&t6, NULL, myvideo, NULL);
			
		}
		if(x > 500 && x < 575 && y > 250 && y < 280) //音乐播放
		{
			system(mp3play[q]);
		}
		if(x > 750 && x < 785 && y > 250 && y < 285) //停止播放音乐
		{
			system("killall -KILL madplay");
		}
		if(x > 635 && x < 680 && y > 250 && y < 285) //切换上一首音乐
		{
			//把正在播放的歌曲关闭
			system("killall -KILL madplay");
			//播放上一首
			if(q>0)
				q--;
			else
				q=3;
			system(mp3play[q]);
		}
		if(x > 565 && x < 600 && y > 312 && y < 342) //切换下一首音乐
		{
			
			//把正在播放的歌曲关闭
			system("killall -KILL madplay");
			//播放下一首
			if(q<3)
				q++;
			else
				q=0;
			system(mp3play[q]);
		}
		

	}
		
		
	}
