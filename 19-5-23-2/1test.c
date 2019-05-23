#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int fd[2];
  char *buf = "hehehe";
  int len = strlen(buf);

  if(pipe(fd)){
    perror("make pip");
    exit(-1);
  }
  write(fd[1],buf,len);
  char msg[100] = {0};
  read(fd[0],msg,len);

  printf("%s\n",msg);
  return 0;
}
