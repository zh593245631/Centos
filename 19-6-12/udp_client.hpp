#include"udp_socket.hpp"

class UdpClient
{
  public:
    UdpClient(const string& ip,uint16_t port)
      :server_ip(ip)
       ,server_port(port)
    {
      _sock.Socket();
    }
    ~UdpClient()
    {
      _sock.Close();
    }
    bool RecvFrom(string* msg){
      return _sock.RecvFrom(msg);
    }
    bool SendTo(string& msg){
      return _sock.SendTo(msg,server_ip,server_port);
    }
  private:
    UdpSocket _sock;
    string server_ip;
    uint16_t server_port;
};
