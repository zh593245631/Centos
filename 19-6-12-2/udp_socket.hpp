#pragma once
#include<sys/socket.h>
#include<unistd.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<cassert>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;

class UdpSocket{
  public:
  UdpSocket()
    :_fd(-1)
  {}
  //打开一个udp的socket
  bool Socket()
  {
    _fd = socket(AF_INET, SOCK_DGRAM,0);
    if(_fd < 0)
      return false;
    return true;
  }
  //关闭
  bool Close()
  {
    if(_fd!=-1)
      close(_fd);
    return true;
  }
  //绑定
  bool Bind(const string& ip, uint16_t port)
  {
    //根据参数构造一个sockaddr_in 结构
    sockaddr_in addr; 
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    int ret = bind(_fd,(sockaddr*)&addr, sizeof(addr));
    if(ret < 0){
      return false;
    }
    return true;
  }
  //接收
  bool RecvFrom(string* msg, string* ip = NULL, uint16_t* port = NULL)
  {
    char buf[1024*10] = {0};
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    ssize_t n = recvfrom(_fd, buf, sizeof(buf)-1,0,(sockaddr*)&peer,&len);
    if(n < 0){
      return false;
    }
    *msg = buf;
    if(ip!=NULL)
      *ip = inet_ntoa(peer.sin_addr);
    if(port!=NULL)
      *port = ntohs(peer.sin_port);
    return true;
  }
  //发送
  bool SendTo(const string& msg,const string& ip, uint16_t port)
  {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    ssize_t n = sendto(_fd,msg.c_str(),msg.size(),0,(sockaddr*)&addr,sizeof(addr));
    if(n < 0){
      return false;
    }
    return true;
  }
  private:
    int _fd;
};
