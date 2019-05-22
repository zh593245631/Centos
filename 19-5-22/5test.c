#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int fd = open("mtfile",O_RDONLY);
  if(fd<0){
    perror("open\n");
    return 1;
  }

  char buf[1024];
  read(fd,buf,20);
  printf("%s\n",buf);

  close(fd);
  return 0;
}
