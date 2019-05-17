#include<stdio.h>

extern int Add(int a, int b);
int main()
{
  printf("add: %d\n", Add(1,3));
  return 0;
}
