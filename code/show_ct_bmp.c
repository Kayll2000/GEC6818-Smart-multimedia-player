#include<stdio.h>
#include"mysql.h"
#include"show_ctbmp.h"
/*
	居中显示图片
	bmp_name：文件名
*/
int show_ct_bmp(char * bmp_name)
{
	printf("%s\n",bmp_name);
	char hbuf[54] = {0};				//存储头信息
	char bmp_buf[FB_W*FB_H*3] = {0};	//存储char型像素数据
	int  lcd_buf[FB_W*FB_H]	= {0};		//存储int型像素数据
	
	int bmp_fd = open(bmp_name,O_RDWR);
	if(bmp_fd < 0)
	{
		printf("open %s fail\n",bmp_name);
		return -1;
	}
	//读取54个字节 头信息
	read(bmp_fd,hbuf,sizeof(hbuf));
	//通过小端模式求出位图的宽度和高度
	int width = hbuf[18] | hbuf[19]<<8 | hbuf[20]<<16 | hbuf[21]<<24;
	int height = hbuf[22] | hbuf[23]<<8 | hbuf[24]<<16 | hbuf[25]<<24;
	//printf("width = %d\n",width);
	//printf("height = %d\n",height);
	
	
	int x_s,y_s;//图片显示的起始位置
	get_pic_xy_s(width,height,&x_s,&y_s);
	
	//读取图片像素数据
	read(bmp_fd,bmp_buf,width*height*3);
	
	//像素数据的处理
	int i,j;
	for(i = 0,j = 0;i < width*height;i++,j+=3) //j+=3 ==> j=j+3
	{
		lcd_buf[i] = (bmp_buf[j+2]<<16) | (bmp_buf[j+1]<<8) | (bmp_buf[j]);
					//		 r					g			   b	
	}
	int x,y;		
	//上下翻转并通过内存映射显示图片
	
	for(y = 0;y < height;y++)
		for(x = 0;x < width;x++)
		{	
			*(lcd+x+x_s+(y+y_s)*FB_W) = lcd_buf[(height-1-y)*width+x];
							//show_buf[y*800+x];
		}

	//关闭文件
	close(bmp_fd);
	
}
