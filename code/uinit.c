#include<stdio.h>
#include"mysql.h"
#include"uinit.h"

/*
	卸载
*/
void uinit()
{
	//取消映射
	munmap(lcd,800*480*4);
	//关闭lcd
	close(lcd_fd);
	//关闭触摸屏
	close(ts_fd);
}
