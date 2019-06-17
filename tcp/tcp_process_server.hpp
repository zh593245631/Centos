#include<iostream>
#include<functional>
#include<signal.h>
#include"tcp_socket.hpp"

typedef function<void (string& req, string* resp)> Handler;
using namespace std;

class TcpProcessServer
{
public:
  TcpProcessServer(const string& ip, uint16_t port):_ip(ip),_port(port)
  {
    signal(SIGCHLD,SIG_IGN);
  }
  bool Start(Handler handler)
  {
    //1.创建socket
   listen_sock.Socket();
   //2.绑定端口号
   listen_sock.Bind(_ip,_port);
   //3.监听
   listen_sock.Listen(5);
   //4.进入事件循环
   while(1)
   {
     //5.进行accept
     TcpSocket new_sock;
     string ip;
     uint16_t port;
     if(!listen_sock.Accept(&new_sock,&ip,&port)){
       continue;
     }
     cout<<"["<<ip<<":"<<port<<"]客户端已连接"<<endl;
     ProcessConnect(new_sock,ip,port,handler);
   }
   return true;
  }
  void ProcessConnect(TcpSocket& new_sock, string& ip, uint16_t port, Handler handler)
  {
    int ret = fork();
    if(ret > 0){
      new_sock.Close();
      return;
    }
    else if(ret < 0){
      cerr<<"fork false";
      return;
    }
    //child
    while(1)
    {
      string req;
      bool ret = new_sock.Recv(&req);
      if(!ret){
        cout<<"["<<ip<<":"<<port<<"]客户端已断开连接"<<endl;
        exit(0);
      }

      cout<<"["<<ip<<":"<<port<<"]"<<"req: "<<req<<endl;
      string resp;
      handler(req,&resp);
      new_sock.Send(resp);
      cout<<"resp: "<<resp<<endl;
    }

  }
private:
  TcpSocket listen_sock;
  string _ip;
  uint16_t _port;
};
