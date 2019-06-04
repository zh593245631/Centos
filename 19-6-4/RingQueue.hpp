#pragma once
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define NUM 9
using namespace std;

template<class T>
class RingQueue{
  public:
    RingQueue(int cap = NUM)
      :_cap(cap)
    {
      _q.resize(cap);
      sem_init(&data_sem,0,0);
      sem_init(&space_sem,0,cap);
      consume_step = 0;
      product_step = 0;
    }
    ~RingQueue()
    {
      sem_destroy(&data_sem);
      sem_destroy(&space_sem);
    }
    void Push(const T& data)
    {
      sem_wait(&space_sem);
      _q[consume_step] = data;
      ++consume_step;
      consume_step %= _cap;
      sem_post(&data_sem);
    }
    void Pop(T& data)
    {
      sem_wait(&data_sem);
      data = _q[product_step];
      ++product_step;
      product_step %= _cap;
      sem_post(&space_sem);
    }
  private:
    vector<T> _q;
    int _cap;
    sem_t data_sem;
    sem_t space_sem;
    int consume_step;
    int product_step;
};
