#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>

int main()
{
   umask(0);
   if(mkfifo("mypipe", 0644) < 0){
      perror("mkfifo");
      exit(-1);
   }

  printf("please wait..\n");
  int fd = open("mypipe",O_RDONLY);
  if(fd<0){
    perror("open");
    exit(-1);
  }

  char buf[1024] = {0};

  while(1)
  {
    size_t s = read(fd,buf,sizeof(buf)-1);
    if(s>0){
      buf[s] = '\0';
      printf("client say:%s\n",buf);
    }
    else if(s == 0){
      printf("client quit\n");
      exit(0);
    }
    else{
      printf("read \n");
    }
  }
  return 0;
}
