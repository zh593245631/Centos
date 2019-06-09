#include<iostream>
#include<queue>
#include<pthread.h>
#include"threadpool.hpp"
#include<unistd.h>

class MyTask : public Task
{
  public:
    void Run()
    {
      cout<<"haha"<<endl;
      sleep(10);
    }
};
int main()
{

  ThreadPool q(4);
  MyTask mytask;
  int i = 0;
  for(;i<10;++i)
  q.AddTask(&mytask);

  return 0;
}
