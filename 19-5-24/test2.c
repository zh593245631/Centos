#include<stdio.h>
#include<signal.h>

volatile int flag = 1;//告诉编译器这个变量必须每次都从内存读取，不敢给我乱优化
//保护内存
//经常使用在多线程程序中 编译器对于这种多执行流的情况是不太会判断
void test(int sig)
{
  printf("%d\n",sig);
  flag = 0;
}

int main()
{
  signal(2,test);
  while(flag);
  return 0;
}
