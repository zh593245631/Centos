#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_rwlock_t lock;
//一个交易场所：有一块存储区域来保存数据(也可以是队列，各种数据结构)
//两种角色 读者 写者
//三种关系：读者和读者之间没有关系 写者和写者之间互斥关系，读者和写者之间同步互斥写者优先
//1.交易场所
int g_count = 0;
//2.两种角色
void* Reader(void* arg)
{
  (void)arg;
  while(1)
  {
    cout<<"g_count = "<<g_count<<endl;
    sleep(1);
  }
  return NULL;
}
void* Writer(void* arg)
{
  (void)arg;
  int count = 0;
  while(1)
  {
    //pthread_rwlock_wrlock(&lock);
    ++count;
    g_count = count;
    //pthread_rwlock_rdlock(&lock);
    sleep(1);
  }
  return NULL;
}
int main()
{
  pthread_rwlock_init(&lock,NULL);
  pthread_t pid1,pid2,pid3;
  pthread_create(&pid1,NULL,Writer,NULL);
  pthread_create(&pid2,NULL,Reader,NULL);
  pthread_create(&pid3,NULL,Writer,NULL);

  pthread_join(pid1,NULL);
  pthread_join(pid2,NULL);
  pthread_join(pid3,NULL);
  pthread_rwlock_destroy(&lock);
  return 0;
}
