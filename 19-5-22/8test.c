#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  close(1);
  int fd = open("myfile", O_WRONLY|O_CREAT, 00644);
  if(fd<0){
    perror("open\n");
    return 1;
  }
  printf("fd: %d\n",fd);
  //fflush(stdout);//文件遇见\n不会刷新缓冲区

  close(fd);
  return 0;
}
