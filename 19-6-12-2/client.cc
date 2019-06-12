#include<iostream>
#include"udp_client.hpp"
using namespace std;

int main()
{
  UdpClient c("127.0.0.1",9090);
  while(1)
  {
    string msg;
    cout<<"请输入查询单词:"<<flush;
    cin>>msg;
    c.SendTo(msg);
    c.RecvFrom(&msg);
    cout<<"server: "<<msg<<endl;
  }
  return 0;
}
