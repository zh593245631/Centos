#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  printf("before: %d\n",getpid());
  pid_t ret = fork();
  if(ret<0){
    perror("error\n");
    exit(-1);
  }
  printf("after: %d\n",getpid());
  sleep(3);
  return 0;
}
