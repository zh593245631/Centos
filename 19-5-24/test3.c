#include<signal.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void hehe(int sig)
{

  printf("child exit\n");
  //wait(NULL);
  /*while(1){
    int ret = waitpid(-1,NULL,NON);
  }*/
}
int main()
{
  //signal(SIGCHLD, SIG_IGN);
  signal(17,hehe);
  int i = 0; 
  for(;i<20; ++i){
    pid_t ret = fork();
    if(ret == 0){
      printf("hehehepid %d\n",getpid());
      exit(0);
    }
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}
