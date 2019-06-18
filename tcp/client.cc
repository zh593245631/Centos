#include<iostream>
#include"tcp_client.hpp"
using namespace std;

int main(int argc, char* argv[])
{
  if(argc != 3){
    printf("请输入[ip] [port]\n");
    return 0;
  }
  TcpClient c(argv[1],atoi(argv[2]));
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
