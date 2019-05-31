#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_cond_t cond2;
void* ThreadEntry1(void* arg)
{
  (void)arg;
  while(1){
    printf("传球\n");
    pthread_cond_signal(&cond);
    usleep(789789);
  }
  return NULL;
}
void* ThreadEntry2(void* arg)
{
  (void)arg;
  while(1){
    pthread_cond_wait(&cond,&mutex);
    printf("扣篮\n");
    usleep(789789);
  }
  return NULL;
}
int main()
{
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&cond,NULL);
  pthread_cond_init(&cond2,NULL);
  pthread_t tid1,tid2;

  pthread_create(&tid1,NULL,ThreadEntry1, NULL);
  pthread_create(&tid2,NULL,ThreadEntry2, NULL);


  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  pthread_cond_destroy(&cond2);
  return 0;
}
