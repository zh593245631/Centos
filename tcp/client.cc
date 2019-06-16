#include<iostream>
#include"tcp_client.hpp"
using namespace std;

int main()
{
  TcpClient c("192.168.199.129",9090);
  c.Connect();
  while(1)
  {
    string msg;
    cout<<"请输入查询单词:"<<flush;
    cin>>msg;
    c.Send(msg);
    string mmm;
    c.Recv(&mmm);
    cout<<"server: "<<mmm<<endl;
  }
  return 0;
}
