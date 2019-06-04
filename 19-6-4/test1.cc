#include<iostream>
#include"threadpool.hpp"

using namespace std;

class MyTask:public Task
{
public:
    MyTask(int id):_id(id)
    {}
    void run()
    {
      printf("id = %d\n",_id);
    }
private:
    int _id;
};
int main()
{
  return 0;
}
