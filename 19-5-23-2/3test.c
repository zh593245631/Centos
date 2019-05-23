#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
  int fd[2];
  if(pipe(fd)== -1){
    perror("pipe\n");
    exit(-1);
  }

  pid_t ret = fork();
  if(ret<0){
    perror("fork\n");
  }
  if(ret == 0){
      char mmm[1024];
      read(fd[0],mmm,100);
      write(fd[1],"hello",5);
      exit(0);
  }
  char msg[100] = {0};
  read(fd[0],msg,100);
  printf("%s\n",msg);
  return 0;
}
