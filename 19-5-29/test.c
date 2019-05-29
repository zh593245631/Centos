#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int arr[100000000] = {0};
void* ThreadEntry(void* arg)
{
  (void)arg;
  //size_t i = 0;
  //for(; i<sizeof(arr)/sizeof(arr[0]); ++i)
  //{
  //  arr[i] = i;
  //}
  int count = 5;
  while(1){
    printf("In ThreadEntry\n");
    sleep(1);
    --count;
  }
  pthread_exit(0);//很少用到
  return NULL;
}
//创建进程 pthread_create
//结束线程 pthread_exit pthread_cancel 
//线程等待 pthread_join 回收线程 显式 其实是为了等待对应线程结束后在执行代码
//线程分离 pthread_detach
int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry, NULL);

  printf("In MainThread\n");
  //pthread_cancel(tid);//尽量少用,线程之间抢占式调度，可能线程还没执行完任务就被中断了
  //pthread_join(tid,NULL);
  pthread_detach(tid);
  //size_t i = 0;
  //for(; i<sizeof(arr)/sizeof(arr[0]); ++i)
  //{
  //  printf("%d\n",arr[i]);
  //  //sleep(1);
  //}
  //while(1){
  //printf("In MainThread\n");
  //sleep(1);
  //}
  return 0;
}
