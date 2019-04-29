#include<iostream>
using namespace std;

class A
{
  public:
  A(){
    cout<<"A()"<<endl;
  }
  void B(){
    C();
  }
  void C(){
    cout<<"hehe"<<endl;
    cout<<"hehe"<<endl;
    cout<<"hehe"<<endl;
  }
};

int main()
{
  A a;
  a.B();
  return 0;
}
