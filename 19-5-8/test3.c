#include<stdio.h>
#include<unistd.h>

int main()
{
 // printf("ppid: %d\n", getppid());
 // printf("pid: %d\n", getpid());
 // sleep(60);
  int ret = fork();
  sleep(3);
  printf("%d   %d\n",getpid(),ret);
  return 0;
}
