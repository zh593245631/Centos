#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>

int main()
{
  int fd = open("mypipe",O_WRONLY);
  if(fd<0){
    perror("open");
    exit(-1);
  }
  char buf[1024] = {0};

  while(1)
  {
    printf("please# ");
    fflush(stdout);
    scanf("%s",buf);
    write(fd,buf,strlen(buf));
  }
  return 0;
}
