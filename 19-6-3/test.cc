#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<vector>

using namespace std;

//实现一个生产者消费者模型
//首先得有一个交易场所
vector<int> data;
pthread_mutex_t mutex;
pthread_cond_t cond;
void* Product(void* arg)
{
  (void)arg;
  int count = 0;
  while(1){
    pthread_mutex_lock(&mutex);
    data.push_back(++count) ;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    usleep(666666);
  }
  return NULL;
}

void* Consume(void* arg)
{
  (void)arg;
  //负责把交易场所中的数据取出来
  while(1)
  {
    //每次取最后一个元素
    pthread_mutex_lock(&mutex);
    while(data.empty())
    {
      //1.先释放锁
      //2.等待条件就绪
      //3.如果条件就绪，重新获取锁
      pthread_cond_wait(&cond,&mutex);
    }
    int result = data.back();
    data.pop_back();
    printf("result = %d\n",result);
    pthread_mutex_unlock(&mutex);
    usleep(666666);
  }
  return NULL;
}
int main()
{
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&cond,NULL);
  pthread_t tid1,tid2;
  pthread_create(&tid1,NULL, Product, NULL);
  pthread_create(&tid2,NULL, Consume, NULL);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}

#if 0
//使用队列来表示生产者消费者模型
//同步互斥不一定非得用互斥锁和条件变量来实现
//使用信号量来完成
//信号量就是一个计数器，表示可用资源的个数
//P是申请资源
//V是释放资源
//当计数器值为0时，再去P会发生阻塞
#include<semaphore.h>
sem_t sem;

//阻塞队列 一种常见的数据结构，线程安全版本的队列
class BlockingQueue{

};
int main()
{
  //第二个参数为0表示只能在当前进程中使用
  //第三个便是信号量计数器的初始值
  sem_init(&sem,0,3);

  //P
  sem_wait(&sem);
  printf("P一次\n");
  sem_wait(&sem);
  printf("P一次\n");
  sem_wait(&sem);
  printf("P一次\n");
  //V
  //sem_post(&sem);


  //销毁
  sem_destroy(&sem);
  return 0;
}
#endif
