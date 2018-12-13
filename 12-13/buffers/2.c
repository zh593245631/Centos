#include<stdio.h>
int main()
{
	printf("hello word");
	fflush(stdout);//新添加的行，刷新输出缓冲区
	int i = 0;
	for(;i < 10; i++)
	{
		putchar('.');
		sleep(1);
	}
	return 0;
}

