#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

//////////////////c语言字符串转数字
//atoi
//sscanf/sprintf  
//sscanf(str,"%d",&num)
///////////////c++
//////////////stringstream
//stringstream ss
//string str
//int num
//ss<<str
//ss>>num
/////////////////stoi
//boost
int main(int argc, char* argv[])
{
  if(argc != 3){
    printf("参数错误！呵呵呵\n");
    return 1;
  }
  int signo = atoi(argv[1]+1);
  pid_t pid = atoi(argv[2]);
  int ret = kill(pid,signo);
  if(ret<0){
    perror("kill\n");
    exit(-1);
  }
  //printf("%d\n",signo);
  //printf("%d\n",pid);
  return 0;
}
