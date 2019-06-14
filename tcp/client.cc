#include<iostream>
#include"tcp_client.hpp"
using namespace std;

int main()
{
  TcpClient c("127.0.0.1",9090);
  c.Connect();
  while(1)
  {
    string msg;
    cout<<"请输入查询单词:"<<flush;
    cin>>msg;
    c.Send(msg);
    c.Recv(&msg);
    cout<<"server: "<<msg<<endl;
  }
  return 0;
}
