#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int fd = open("mtfile",O_WRONLY|O_CREAT,0644);
  if(fd<0){
    perror("open\n");
    return 1;
  }

  const char* msg = "hello world\n";
  write(fd,msg,strlen(msg));

  close(fd);
  return 0;
}
