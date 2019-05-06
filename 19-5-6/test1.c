#include<stdio.h>
#include<unistd.h>
int main()
{
  pid_t ret = fork();
  // getpid 获取进程pid
  // getppid 获取父进程pid
  
  if(ret>0)
  {
    //父进程
    printf("father: %d  ret: %d\n", getpid(), ret);
    while(1)
    {
      sleep(1);
    }
  }
  else if(ret == 0){
    int count = 5;
    //子进程
    printf("child: %d  ret: %d\n", getpid(), ret);
    while(count--)
    {
      sleep(1);
    }

  }
  else{
    //创建失败
    perror("fork");
  }
 // printf("pid: %d, ppid: %d, ret: %d \n",getpid(),getppid(),ret);
  sleep(1);
  return 0;

}
