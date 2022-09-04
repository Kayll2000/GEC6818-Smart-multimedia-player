#include<stdio.h>
#include"mysql.h"
#include"lcd_drawbmp.h"

void lcd_draw_bmp(char *file, int w, int h, int x0, int y0)
{
	//先打开bmp图片
	int bmp_fd;
	bmp_fd = open(file, O_RDWR);
	if (-1 == bmp_fd)
	{
		printf("open bmp: %s error !\n", file);
		return ;
	}
	
	char buf[w*h*3 + 54];
	//将bmp图片的像素点读取到buf中
	read(bmp_fd, buf, sizeof(buf));
	
	//将bmp图片显示在LCD上
	int color;
	int i = 0;
	int x, y;
	for (y = 0; y < h; y++)
	{
		for (x = 0; x < w; x++)
		{
			//24位bmp图片的像素点的表示：BGR
			char b, g, r;
			b = buf[54+i];
			g = buf[55+i];
			r = buf[56+i];
			i += 3;
			//将24bitBMP图片的一个像素点表示成LCD的一个像素点
			color = r<<16 | g<<8 | b; 
			lcd_draw_point(x+x0,h-1-y+y0,color);
			//为什么要h-1-y? 因为bmp图片的像素点的存储坐标原点为左下角，而我们认为LCD的坐标原点为左上角
		}
	}
	close(bmp_fd);
}
