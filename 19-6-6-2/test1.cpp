#include<iostream>
#include<thread>
#include<unistd.h>
#include<string>
#include<mutex>
#include<atomic>

//++是三个步骤
//原子操作是cPU级别的锁
//自旋锁
using namespace std;
mutex _lock;
atomic_int count(0);
//int count = 0;
void Handler(int num,string str,shared_ptr<int> p)
{
  shared_ptr<int> p3(p);
  //while(1)
  //{
  // _lock.lock();
  // cout<<"num = " <<num<<" "<<str<<endl;
  // _lock.unlock();
  // sleep(1);
  //}
  int i = 0;
  for(;i < 5000; ++i)
  {
    ++count;
  }
}
int main()
{
  shared_ptr<int> p(new int[10]);//底层原子操作
  thread t1(Handler,1,"hehe",p);
  thread t2(Handler,2,"haha",p);
  t1.join();
  t2.join();
  cout<<count<<endl;
  return 0;
}
//常见面试题
//1.STL是否是线程安全 不是
//STL是c++98，而线程相关操作是C++11加入的
//STL对性能追求到极致，如果考虑到线程安全对性能有很大影响
//2.智能指针是否是线程安全的
//unique_ptr 不涉及线程安全问题（只在一个函数内部使用，）
//shared_ptr c++11和线程一起的，底层是原子操作来维护引用计数，boost先提出的。
//3.实现一个单例模式
// 饿汉模式
// 懒汉模式
//线程安全  加锁之后效率  编译器优化

