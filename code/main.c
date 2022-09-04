#include<stdio.h>
#include"mysql.h"

int main()
{
/*
t1   显示时间
t2	 文字流水
t3	 小球滚动
t4	 屏幕触摸
t5	 照片全屏
t6   视频播放
t7
t8
t9

*/
		int *pk;
		pk = &count;
		/* 初始化*/
		init();
		init1();
		loading();

		/* 开启线程 */

		pthread_create(&t1, NULL, show_time, NULL);//开启显示时间线程
		pthread_create(&t2, NULL, move_biaoti, NULL);//开启标题移动线程
		pthread_create(&t3, NULL, mymoveball, NULL);//开启小球滚动线程
		pthread_create(&t4, NULL, mytouch, NULL);//开启触摸线程
		clear_lcd(0xffffff);//开机清屏
		/* 绘制界面 */
		myshow();
		mydraw();
		myid();
		//循环执行
		while(1);
		//执行退出执行卸载
		uinit();
		return 0;
	

}
/*
		视频操作
        暂停：system("killall  -STOP mplayer"); //给mplayer发送暂停信号
        继续：system("killall  -CONT mplayer"); //给mplayer发送继续信号
        退出：system("killall  -KILL mplayer"); //给mplayer发送杀死信号
*/
