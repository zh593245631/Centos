#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
  close(1);
  //int fd = open("test.txt",O_WRONLY);
  int dd = open("test1.txt",O_WRONLY);
  //printf("%d\n", fd);
  //fprintf(stderr,"fd = %d",fd);
  fprintf(stdout,"hehe",stdout->_fileno);
  fprintf(stdout,"haha",stdout->_fileno);
  return 0;
}
