#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  pid_t ret = fork();

  if(ret<0){
    perror("error\n");
    exit(-1);
  }

  if(ret == 0)
  {
    sleep(20);
    exit(0x1f);
  }
  int st;
  int w = wait(&st);
  if(w>0&&(st&0x7f)==0)
    printf("chirld return %d",(st>>8)&0xff);
  else if(w>0){
    printf("sig return %d", st&0x7f);
  }
  return 0;
}
