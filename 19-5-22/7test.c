#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
  //close(2);
  close(1);
  //close(0);
  int fd = open("myfile",O_RDONLY);

  if(fd<0){
    perror("open\n");
      return 1;
  }
  printf("fd: %d\n",fd);
  return 0;
}
