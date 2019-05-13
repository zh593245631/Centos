#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
  int ret = fork();
  if(ret == 0)
  {
    printf("child1: %d father: %d\n", getpid(),getppid());
    exit(0);
  }
  ret = fork();
  if(ret == 0)
  {
    printf("child2: %d father: %d\n", getpid(),getppid());
    exit(0);
  }

  ret = fork();
  if(ret == 0)
  {
    printf("child3: %d father: %d\n", getpid(),getppid());
    exit(0);
  }
  printf("father: %d\n",getpid());
  ret = wait(NULL);
  printf("wait: %d\n", ret);
  ret = wait(NULL);
  printf("wait: %d\n", ret);
  ret = wait(NULL);
  printf("wait: %d\n", ret);
  ret = wait(NULL);
  printf("wait: %d\n", ret);
  while(1)
  {
    sleep(1);
  }
  return 0;
}
