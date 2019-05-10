#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void Fun()
{
  printf("haha");
  exit(1);
}
int main()
{
  //sleep(3);
  //Fun();
  atexit(Fun);
  //printf("hehe\n");
  return 0;
}
