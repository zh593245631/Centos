//---------------------------------------------------
//不是系统调用------------是库函数
//库函数 =》posix 线程库 pthread 中的 p就表示 posix
//1.创建线程
//2.终止线程
//3.等待线程
//4.线程分离
//
//输出型参数
#include<pthread.h>
/*#define IN
#define OUT
int pthread_create(OUT int* thread_id)
{

}*/
#include<stdio.h>
#include<unistd.h>

typedef void*(*p)(void*);

void* ThreadEntry(void* arg){
  (void)arg;
  while(1){
    printf("In ThreadEntry, %lu\n",pthread_self());
    sleep(1);
  }
}
int main()
{
  pthread_t tid;
  pthread_create(&tid, NULL, ThreadEntry, NULL);//man 看用法

  while(1){
    printf("In main Thread, %lu\n", pthread_self());
    sleep(1);
  }

  return 0;
}

