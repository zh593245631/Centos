#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* ThreaEntry(void* arg)
{
  int* p = (int*)arg;
  //int a = 10/0;
  while(1)
  {
    printf("In TreadEntry\n");
    ++*p;
    sleep(1);
  }
}
int main()
{
  int count = 0;
  pthread_t tid;
  pthread_create(&tid,NULL,ThreaEntry,&count);

  while(1){
    sleep(1);
    printf("In MainTread %d\n",count);
  }
  return 0;
}
