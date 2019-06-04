#pragma once

#include<queue>
#include<stdlib.h>
#include<pthread.h>
#include<iostream>
#define NUM 9
using namespace std;
//一般BlockingQueue 都要求长度是有上限的
//如果队列为空，去执行Pop就会堵塞
//如果队列满了，去执行Push也会堵塞

template<class T>
class BlockingQueue
{
private:
  void LockQueue()
  {
    pthread_mutex_lock(&_lock);
  }
  void UnLockQueue()
  {
    pthread_mutex_unlock(&_lock);
  }
  void ProductWait()
  {
    pthread_cond_wait(&_full,&_lock);
  }
  void ConsumeWait()
  {
    pthread_cond_wait(&_empty,&_lock);
  }
  void NotifyProduct()
  {
    pthread_cond_signal(&_full);
  }

  void NotifyConsume()
  {
    pthread_cond_signal(&_empty);
  }
  bool IsEmpty()
  {
    return _queue.size() == 0;
  }
  bool IsFull()
  {
    return _queue.size() == _cap;
  }
public:
  BlockingQueue(int cap = NUM)
    :_cap(cap)
  {
    pthread_mutex_init(&_lock,NULL);
    pthread_cond_init(&_full,NULL);
    pthread_cond_init(&_empty,NULL);
  }

  ~BlockingQueue()
  {
    pthread_mutex_destroy(&_lock);
    pthread_cond_destroy(&_full);
    pthread_cond_destroy(&_empty);
  }
  void Push(const T& data)
  {
    LockQueue(); 
    while(IsFull())
    {
      NotifyConsume();
      cout<<"queue is Full, notify consume data, product stop--size:"<<_queue.size()<<endl;
      ProductWait();
    }
    _queue.push(data);
    UnLockQueue();
  }

  void Pop(T& data)
  {
    LockQueue();
    while(IsEmpty())
    {
      NotifyProduct();
      cout<<"queue is Empty, notify product data,consume stop--size:"<<_queue.size()<<endl;
      ConsumeWait();
    }
    data = _queue.front();
    _queue.pop();
    UnLockQueue();
  }
private:
 queue<T> _queue; 
 int _cap;
 pthread_mutex_t _lock;
 pthread_cond_t _full;
 pthread_cond_t _empty;
};
