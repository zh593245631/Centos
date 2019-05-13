#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  pid_t ret = fork();
  if(ret == 0)
  {
    printf("before execl\n");
    execl("/usr/bin/ls","/usr/bin/ls","/",NULL);
  }
  wait(NULL);
  printf("after execl\n");
  return 0;
}
