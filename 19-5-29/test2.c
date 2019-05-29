#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdint.h>

#if 0
void* ThreadEntry(void* arg)
{
  (void)arg;
  while(1);
}

int main()
{
  pthread_t tid1,tid2,tid3,tid4,tid5,tid6,tid7,tid8;
  pthread_create(&tid1,NULL,ThreadEntry, NULL);
  pthread_create(&tid2,NULL,ThreadEntry, NULL);
  pthread_create(&tid3,NULL,ThreadEntry, NULL);
  pthread_create(&tid4,NULL,ThreadEntry, NULL);
  pthread_create(&tid5,NULL,ThreadEntry, NULL);
  pthread_create(&tid6,NULL,ThreadEntry, NULL);
  pthread_create(&tid7,NULL,ThreadEntry, NULL);
  pthread_create(&tid8,NULL,ThreadEntry, NULL);

  while(1);
  return 0;
}
#endif

//通过多线程提高程序的执行效率
//假设存在一个很大的数组，把数组中的每个元素都进行一个乘方
#include<malloc.h>
#include<sys/time.h>

#define SIZE 100000000

int64_t GetUs()
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec * 1000000 + tv.tv_usec;
}
void Calc(int* arr, int beg, int end)
{
  int i = beg;
  for(;i<end; ++i)
  {
    arr[i] = arr[i]*arr[i];
  }
}
#if 0
int main()
{
  int* arr = (int*)malloc(sizeof(int)*SIZE);
  time_t beg = GetUs();
  Calc(arr,0,SIZE);
  time_t end = GetUs();

  printf("%lu\n",end - beg);
  return 0;
}
#endif

#define THREAD_NUM 2 
//多线程版本

typedef struct Arg
{
  int beg;
  int end;
  int* arr;
}Arg;

void* ThreadEntry(void* arg)
{
  Arg*p = (Arg*)arg;
  Calc(p->arr, p->beg, p->end);
  return NULL;
}
int main()
{
  int* arr = (int*)malloc(sizeof(int)*SIZE);
  Arg args[THREAD_NUM];
  int base = 0;
  int i = 0;
  for(;i<THREAD_NUM;++i)
  {
    //分组数据
    args[i].beg = base;
    args[i].end = base+SIZE/THREAD_NUM;
    args[i].arr = arr;
    base = args[i].end;
  }

  pthread_t tid[THREAD_NUM]; 
  //开始时间
  int64_t beg = GetUs();
  //创建多个线程分别去执行
  for(i = 0;i<THREAD_NUM; ++i)
  {
    pthread_create(&tid[i], NULL, ThreadEntry, &args[i]);
  }

  //分别等待线程处理完任务
  for(i = 0; i<THREAD_NUM; ++i)
  {
    pthread_join(tid[i],NULL);
  }
  //结束时间
  int64_t end = GetUs();

  printf("%lu\n",end - beg);
  return 0;
}

