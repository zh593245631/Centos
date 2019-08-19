#include<sys/wait.h>
#include<unistd.h>
#include<iostream>

using namespace std;
int main()
{
  pid_t ret = fork();
  if(ret < 0){
    cerr<<"fork"<<endl;
    return -1;
  }
  else if(ret == 0){
    //子
    cout<<"子进程："<<getpid()<<endl;
    sleep(10);
    return 0;
  }
  else{
    //父
    cout<<"父进程：wait start"<<getpid()<<endl;
    //wait(NULL);
    //WUNTRACED  WNOHANG
    waitpid(ret,NULL,WUNTRACED);
    cout<<"父进程：wait end"<<getpid()<<endl;
  }
  return 0;
}
