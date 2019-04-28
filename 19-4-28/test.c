#include<stdio.h>
void Func3()
{
  printf("hehe\n");
  printf("hehe\n");
  printf("hehe\n");
  printf("hehe\n");
}
void Func2()
{
  Func3();
}
void Func1()
{
  Func2();
}

int main()
{
  Func1();
  return 0;
}
