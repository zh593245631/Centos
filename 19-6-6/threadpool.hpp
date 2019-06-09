#pragma once
#include<iostream>
#include"blockingqueue.hpp"

using namespace std;
class Task{
public:
    virtual void Run()
    {
      cout<<"hehe"<<endl;
    }
};
//线程池对象启动时会创建一组线程
//每个线程都需要完成一定的任务（执行一定的代码逻辑，这个逻辑是由调用者来决定的）
//任务是一段代码，可以用函数来表示
class ThreadPool:public Task
{
 public:
  //n 表示创建线程的数量 
  ThreadPool(int n)
    :_queue(n)
  {}
  //使用线程池的时候，就需要由调用者加入一些任务
  //让线程池去执行
  void AddTask(Task* task)
  {
    _queue.Push(task);    
    //task->Run();
    //_queue.Pop(task);
  }
 private:
  BlockingQueue<Task*> _queue;
};
