#include<stdio.h>
#include"mysql.h"
#include"get_xy.h"
/*
	获取坐标值
*/
void get_x_y(int *x,int *y)
{
	struct input_event ts;
	int count = 0;
	while(1)//等价于 for(;;) 死循环
	{
		
		read(ts_fd,&ts,sizeof(ts));
		if(ts.type == EV_ABS && ts.code == ABS_X) //判断为x坐标事件
		{
			*x = ts.value;
			count++;
		}
		if(ts.type == EV_ABS && ts.code == ABS_Y) //判断为y坐标事件
		{
			*y = ts.value;	
			count++;
		}
		if(count == 2)
		{
			printf("x = %d,y = %d\n",*x,*y);
			count = 0;
			return ;
		}
		
	}
}
