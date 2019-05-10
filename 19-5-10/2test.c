#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  pid_t ret = fork();

  if(ret>0)
  {
    printf("father:  %d\n", getpid());
    int status = 0;
    int result = wait(&status);
    printf("result : %d,  stauts: %d\n",result,status);
  }else if(ret == 0)
  {
    int count = 3;
    while(count--)
    {
      printf("chirld:  %d\n",getpid());
      sleep(1);
    }
    exit(2);
  }
  return 0;
}
