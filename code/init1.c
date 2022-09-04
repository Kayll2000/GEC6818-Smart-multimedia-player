#include<stdio.h>
#include"mysql.h"
#include"init1.h"


void init1()//初始化2
{
	//打开LCD
    fd = open("/dev/fb0", O_RDWR);
	if (fd == -1) //if (-1 == fd)
	{
		//打开失败
		printf("open lcd error !\n");
		return ;
	}
	//内存映射：将一个文件/设备映射到一段内存上
	//我们用一个指针指向映射的内存的起始地址，
	//那么我们操作这个指针就相当于在操作映射的文件
	//memory map
	//mmap返回一个映射成功的内存空间的起始地址
	plcd = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	white_back();
	ts_fd = open("/dev/input/event0",O_RDWR);
		if(ts_fd < 0)
	{
		printf("open ts fail\n");
		return ;
	}
	srand((unsigned)time(NULL));//用当前时间，设置种子 
		
}
