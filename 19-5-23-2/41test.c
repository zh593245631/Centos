#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int outfd = open("edf", O_WRONLY);

  int infd = open("fifo",O_RDONLY);


  char buf[100];
  read(infd,buf,100);
  write(outfd, buf, 100);

  close(infd);
  close(outfd);
  return 0;
}
