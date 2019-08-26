#pragma once
#include<sys/socket.h>
#include<arpa/inet.h>// sockaddr_in 结构体
#include<unistd.h>
#include<cstring>
#include<string>
using namespace std;

class udp_socket
{
public:
  udp_socket(int fd = -1):_fd(fd){}
  bool Socket()
  {
    // AF_INET --- ipv4
    // SOCK_DGRAM --- UDP
    _fd = socket(AF_INET,SOCK_DGRAM, 0);

    if(_fd < 0){
      return false;
    }

    return true;
  }

  bool Close()
  {
    if(close(_fd) == -1)
      return false;
    return true;
  }

  bool Bind(const string& ip, const uint16_t& port) const
  {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);

    if(bind(_fd, (sockaddr*)&addr,sizeof(addr)) < 0)
      return false;
    return true;
  }

  bool Recv(string* info, string* ip = nullptr, uint16_t* port = nullptr) const
  {
    char tmp[1024 * 10] = {0};
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    ssize_t n = recvfrom(_fd,tmp,sizeof(tmp) - 1, 0, (sockaddr*)&peer,&len);
    if( n < 0  ){
      return false;
    }
    tmp[n] = '\0';
    *info = tmp;
    if(ip){
      *ip = inet_ntoa(peer.sin_addr);
    } 
    if(port){
      *port = ntohs(peer.sin_port);
    }
    return true;
  }

  bool Send(const string& info, const string& ip, const uint16_t& port)
  {
    sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_addr.s_addr = inet_addr(ip.c_str());
    peer.sin_port = htons(port);
    ssize_t n = sendto(_fd,info.c_str(),strlen(info.c_str()),0,(sockaddr*)&peer, sizeof(peer));
    if( n < 0 )
      return false;
    return true;
  }
 int Getfd()
 {
   return _fd;
 }
private:
    int _fd;
};
