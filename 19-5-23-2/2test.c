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
      close(fd[0]);
      write(fd[1],"hello",5);
      close(fd[1]);
      exit(0);
  }
  close(fd[1]);
  char msg[100] = {0};
  read(fd[0],msg,5);
  printf("%s\n",msg);
  return 0;
}
