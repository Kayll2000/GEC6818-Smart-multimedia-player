#ifndef _MYSQL_H_
#define _MYSQL_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<linux/input.h>
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
#include<termios.h>
#include<sys/ioctl.h>
#include<pthread.h>
#include<sys/socket.h>
#include<linux/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#include"clearlcd.h"
#include"draw_ball.h"
#include"draw_digit.h"
#include"draw_frame.h"
#include"draw_hline.h"
#include"draw_point.h"
#include"draw_rectangle.h"
#include"draw_word.h"
#include"get_picxy.h"
#include"get_xy.h"
#include"init.h"
#include"init1.h"
#include"lcd_drawbmp.h"
#include"loading.h"
#include"move_ball.h"
#include"move_biaoti.h"
#include"mydraw.h"
#include"myid.h"
#include"mymoveball.h"
#include"myshow.h"
#include"myshow1.h"
#include"mysign.h"
#include"mytouch.h"
#include"myvideo.h"
#include"show_bmp.h"
#include"show_ctbmp.h"
#include"show_time.h"
#include"uinit.h"
#include"white_back.h"
/*
*定义变量的
*/
#define FB_W 800
#define FB_H 480
#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF
#define WHITE 0xFFFFFFFF
#define BLACK 0
#define WATHET 0x0000FFFF
#define GRAY 0x00C0C0C0
#define YELLOW 0x00FFFF00
#define mycolor 0x00FFFF
#define mycolor1 0xFFD700
#define mycolor2 0xF0FF00
#define mycolor3 0xFF00FF
#define mycolor4 0x00EE76

/*全局变量，作用域：整个.c文件*/
extern int lcd_fd;
extern int *lcd;
extern int time0;
extern  int count;
extern  int *p;
extern  pthread_t t1,t2,t3,t4,t5,t6,t7,t7,t8,t9;
extern  int ts_fd;
extern  int x_falg;//碰到左半边 0 碰到右半边 1
extern  int y_falg;
extern  int myflag;
extern  int g;
extern  int q;//第几首音乐
extern  int fd;
extern  int *plcd;
extern  int pthread_flag;
extern  int touch_flag; 
/*
***函数声明
***区域
***！！！
*/

extern  void clear_lcd(int color);
extern  void lcd_draw_point(int x, int y, int color);
extern  void lcd_draw_rectangle(int x,int y,int w,int h,int color);
extern  void lcd_draw_hline(unsigned int x,unsigned int y,unsigned int len,unsigned int direction,unsigned int color);
extern  void lcd_draw_frame(unsigned int x,unsigned int y,unsigned int len_x,unsigned int len_y,unsigned int color);
extern  void lcd_draw_word(char *ch, int len, int w, int color, int x0, int y0);
extern  void lcd_draw_bmp(char *file, int w, int h, int x0, int y0);
extern  void white_back();
extern  void lcd_draw_digit(int value,int x0, int y0, int color);
extern  void get_x_y(int *x,int *y);
extern  void get_pic_xy_s(int width,int height,int *x_s,int *y_s);
extern  void init();
extern  void init1();
extern  void uinit();
extern  void draw_ball(int x0 ,int y0, int r,int color);
extern  void move_ball(int x0 ,int y0, int r,int color);
extern  void *mymoveball();
extern  void *move_biaoti();
extern  void *show_time();
extern  int show_bmp(int x_s,int y_s,char * bmp_name);
extern  void mydraw();
extern  void myshow();
extern  void myid();
extern  void *mytouch();
extern  void *myshow1();
extern  int show_ct_bmp(char * bmp_name);
extern  void mysign();
extern  void loading();

/*
*数组定义区域
*/
extern char mp3play[4][50];
extern char music[12][72];
extern char video[4][72];
extern char change[4][72];
extern unsigned char date_arr[][24*21];
extern unsigned char quanping[][21*24];
//开机加载图片
extern char *bmp_loading[5];
//代号
extern char id1[3][32];
extern char id2[3][32];
extern char id3[3][32];
extern char id4[3][32] ;
//小型logo
extern char *bmp_photo1[5];
//小型照片
extern char *bmp_name[12];
extern char *bmp_photo[9];
extern unsigned char move[][32*36];
extern unsigned char num[][16*21];
//0~9的模，宽度16
extern unsigned char w_digit[][58];
#endif
