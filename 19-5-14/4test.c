#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
  pid_t a = fork();
  if(a == 0)
  {
    sleep(10);
    printf("chirld\n");
  }
  wait(NULL);
  printf("father\n");
  while(1)
  {
    sleep(1);
  }
  return 0;
}
