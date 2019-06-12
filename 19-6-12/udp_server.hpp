#pragma once
#include"udp_socket.hpp"

class UdpServer
{
public:
  UdpServer(){
    assert(_sock.Socket());
  }
  bool Start(const string& ip, uint16_t port)
  {
    //1.创建socket完成
    //2.绑定端口号
    bool ret = _sock.Bind(ip,port);
    if(!ret)
      return false;
    //3.进入死循环
    while(1)
    {
      string req;
      string peer_ip;
      uint16_t peer_port;
      _sock.RecvFrom(&req,&peer_ip,&peer_port);
      cout<<req<<endl;
      _sock.SendTo(req,peer_ip,peer_port);
    }
  }
  private:
  UdpSocket _sock;
};
