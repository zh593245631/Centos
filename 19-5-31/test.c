#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

//互斥机制的使用
//1.先加锁
//2.执行临界区代码
//3.释放锁
//-----------------------------------------------------------
//同一时刻只能有一个线程获取到锁，
#define THREAD_NUM 3
//------------------------------------------------------------
//互斥量/
//pthread_mutex_t 挂起等待锁， 一旦线程获取失败就会挂起，这个线程
//什么时候才能恢复执行，也不是其他线程释放锁立刻就能执行
//互斥锁能够保证线程安全，最终的程序效率会收到影响
//最严重的问题 会导致死锁
//两个线程1，2，两把锁A，B，线程1先去获取锁A,再去获取锁B 
//同时 线程2去先获取锁B，再去获取锁A，也会死锁。
//------------------------------------------------------------
//哲学家就餐问题
//
//可重入函数
//一个函数在任意的执行流中调用，都不会出问题
//线程安全函数
//一个函数在任意的线程中调用
//可重入概念要求更高涵盖了线程安全
//如果一个函数可重入则这个函数线程安全
//一个函数线程安全不一定可重入
pthread_mutex_t mutex;
int g_count = 0;

void ModeifyCount()
{
  pthread_mutex_lock(&mutex);
  ++g_count;
  printf("befor\n");
  sleep(3);
  printf("after\n");
  pthread_mutex_unlock(&mutex);
}
void* ThreadEntry(void* arg)
{
  (void)arg;
  int i = 0;
  for(;i<5000;++i){
    //pthread_mutex_lock(&mutex);
    //pthread_mutex_lock(&mutex); //死锁
    //++g_count;
    ModeifyCount();
    //pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
void MyHandler(int sig)
{
  (void)sig;
  ModeifyCount();
}
int main()
{
  signal(SIGINT,MyHandler);
  pthread_mutex_init(&mutex,NULL);

  pthread_t tid[THREAD_NUM];

  int i = 0;
  for(;i<THREAD_NUM;++i){
    pthread_create(&tid[i],NULL,ThreadEntry, NULL);
  }

  for(i = 0; i<THREAD_NUM; ++i)
  {
    pthread_join(tid[i],NULL);
  }
  printf("%d\n",g_count);

  pthread_mutex_destroy(&mutex);
  return 0;
}
