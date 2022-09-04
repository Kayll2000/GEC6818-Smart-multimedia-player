#include<stdio.h>
#include"mysql.h"
#include"white_back.h"

//清屏
void white_back()
{
	int i;
	for(i=0;i<800*480;i++)
		*(lcd+i) = WHITE;
	
}
