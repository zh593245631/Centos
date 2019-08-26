#pragma once
#include"udp_socket.hpp"
#include<iostream>
using namespace std;

typedef void (*Handler)(const string& req,string* resp);

class udp_server
{
public:
  udp_server(const string& ip, const uint16_t& port):_ip(ip),_port(port){}

  ~udp_server()
  {
   _socket.Close();
  }

  bool Start(Handler handler)
  {
    //1. 创建文件描述符
    if(!_socket.Socket()){
      clog<<"get fd false"<<endl;
      return false;
    }
      clog<<"get fd = "<<_socket.Getfd()<<endl;
    //2. 绑定端口号
    if(!_socket.Bind(_ip,_port)){
      clog<<"udp_server start false"<<endl;
      return false;
    }
      clog<<"udp_server start"<<endl;
    //3. 进入事件主循环
    while(1) 
    {
      string req;
      string ip;
      uint16_t port;
      // a) 接收客户端请求
      if(!_socket.Recv(&req,&ip,&port)){
        clog<<"Recv false"<<endl;
        continue;
      }
      printf("[client:%s-%d]: %s\n",ip.c_str(),port,req.c_str());
      string resp;
      // b) 根据请求计算响应
      handler(req,&resp);
      // c) 将结果返回给客户端
      if(!_socket.Send(resp,ip,port)){
        clog<<"Send false"<<endl;
        continue;
      }
    }
      return true;
  }
  
private:
  udp_socket _socket;
  string _ip;
  uint16_t _port;
};
