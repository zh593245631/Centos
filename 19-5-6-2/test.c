#include<stdio.h>
void fun1()
{
  printf("hehe\n");
}

void fun2()
{
  fun1();
}

void fun3()
{
  fun2();
}
int main()
{
  fun3();
  return 0;
}
