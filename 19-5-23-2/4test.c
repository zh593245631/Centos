#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int infd = open("abc", O_RDONLY);
  if(infd == -1){
    perror("open");
    exit(-1);
  }

  int outfd = open("fifo",O_WRONLY);
  if(outfd == -1){
    perror("open");
    exit(-1);
  }

  char buf[10];
  read(infd,buf,5);
  write(outfd, buf, 3);

  close(infd);
  close(outfd);
  return 0;
}
