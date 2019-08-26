#pragma once
#include"udp_socket.hpp"
#include<iostream>

using namespace std;

class udp_client
{
public:
  udp_client(const string& ip,const uint16_t& port):_ip(ip),_port(port)
  {
    if(!_socket.Socket()){
      clog<<"get fd false"<<endl;
      return;
    }
    clog<<"get fd = "<<_socket.Getfd()<<endl;
  }

  ~udp_client()
  {
    _socket.Close();
  }

  bool Recv(string* info)
  {
    if(!_socket.Recv(info)){
      clog<<"Recv false"<<endl;
      return false;
    }
    return true;
  }

  bool Send(const string& info)
  {
    if(!_socket.Send(info,_ip,_port)){
      clog<<"Send false"<<endl;
      return false;
    }
    return true;
  }

private:
  udp_socket _socket;
  string _ip;
  uint16_t _port;
};
