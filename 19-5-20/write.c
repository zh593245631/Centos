#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fd = open("./yhs",O_RDONLY);
  if(fd<0)
  {
    perror("open");
    return -1;
  }
  while(1)
  {}
  return 0;
}
