#include<stdio.h>
#include<unistd.h>
int main()
{
	fprintf(stderr,"hello word");
	int i = 0;
	for(;i < 10; i++)
	{
		fprintf(stderr,".");
		sleep(1);
	}
	return 0;
}
