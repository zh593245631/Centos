#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
  pid_t ret = fork();
  
  if(ret>0)
  while(1)
  {
    sleep(1);
  }

  return 0;
}
