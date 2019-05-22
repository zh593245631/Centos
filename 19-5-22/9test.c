#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fd = open("./log",O_CREAT|O_RDWR);
  if(fd<0){
    perror("open\n");
    return 1;
  }
  close(1);
  dup2(fd,1);
  char buf[10] = {0};
  ssize_t ret = read(0,buf,sizeof(buf)-1);
  if(ret<0){
    perror("read\n");
    return 1;
  }
  printf("%s\n",buf);
  return 0;
}
