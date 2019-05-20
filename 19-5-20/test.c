#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int fd[2];
  int ret = pipe(fd);
  if(ret<0){
    perror("pipe");
    return -1;
  }
  ret = fork();

  if(ret>0){
    //father
    //写数据
    char buf[1024] = "hehe";
    write(fd[1],buf,strlen(buf));
  }else if(ret == 0){
  //child
    char buf_output[1024] = {0};
    read(fd[0],buf_output,sizeof(buf_output)-1);
    printf("%s\n",buf_output);
  }
  else{
    perror("fork");
  }
  close(fd[0]);
  close(fd[1]);
}
