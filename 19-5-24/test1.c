#include<signal.h>
#include<stdio.h>

void hehe(int sig){
  printf("signal=%d\n",sig);
}

int main()
{
  signal(2,hehe);
  
  while(1);
  return 0;
}
