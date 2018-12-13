#include<stdio.h>
int main()
{
	printf("hello word");
	int i = 0;
	for(;i < 10; i++)
	{
		putchar('.');
		sleep(1);
	}
	return 0;
}

