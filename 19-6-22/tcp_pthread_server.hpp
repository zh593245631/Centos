#include<iostream>
#include<pthread.h>
#include<functional>
#include"tcp_socket.hpp"

using namespace std;
typedef function<void (string& req,string* resp)> Handler;
struct Arg{
  TcpSocket new_sock;
  string ip;
  uint16_t port;
  Handler handler;
};
class TcpPthreadServer
{
public:
  TcpPthreadServer(const string& ip, uint16_t port):_ip(ip),_port(port){}

  bool Start(Handler handler)
  {
    //1.创建socket
    listen_sock.Socket();
    //2.绑定ip 端口号
    listen_sock.Bind(_ip,_port);
    //3.监听
    listen_sock.Listen(5);
    //4.进入事件主循环
    while(1)
    {
      //5.进行accept
      Arg* arg = new Arg(); 
      arg->handler = handler;
      if(!listen_sock.Accept(&arg->new_sock,&arg->ip,&arg->port)){
        continue;
      }
      cout<<"["<<arg->ip<<":"<<arg->port<<"]"<<"客户端已连接"<<endl;
      //6.创建线程
      pthread_t tid;
      pthread_create(&tid,NULL,ThreadEntry,arg);
      pthread_detach(tid);
    }
    return true;

  }
  static void* ThreadEntry(void* arg)
  {
    Arg* Targ = (Arg*)arg;
    while(1)
    {
      //1.读取请求
      string req;
      bool ret = Targ->new_sock.Recv(&req);
      if(!ret){ 
        cout<<"["<<Targ->ip<<":"<<Targ->port<<"]"<<"客户端已断开连接"<<endl;
        break;
      }  
      cout<<"["<<Targ->ip<<":"<<Targ->port<<"]"<<endl<<"req: "<<endl<<req<<endl;
      //2.根据请求计算响应
      string resp;
      Targ->handler(req,&resp);
      //3.发送响应
      Targ->new_sock.Send(resp);
      cout<<"resp: "<<endl<<resp<<endl;
    }
    Targ->new_sock.Close();
    Targ = nullptr;
    return nullptr;
  }
private:
  TcpSocket listen_sock;
  string _ip;
  uint16_t _port;
};
