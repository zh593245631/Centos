#pragma once
#include<functional>
#include"tcp_socket.hpp"
typedef std::function<void (string& req, string* resp)> Handler;
class TcpServer
{
 public:
    TcpServer(const string& ip, uint16_t port):_ip(ip),_port(port){}

    bool Start(Handler handler)
    {
        //1.创建socket
        _listen_sock.Socket();
        //2.绑定端口号
        _listen_sock.Bind(_ip,_port);
        //3.进行监听
        _listen_sock.Listen(5);
        //4.进入事件循环
        while(1)
        {
          //5.进行accept
          TcpSocket new_sock;
          string peer_addr;
          uint16_t peer_port;
          if(!_listen_sock.Accept(&new_sock,&peer_addr,&peer_port)){
            continue;
          }
          clog<<"[client "<<peer_addr<<": "<<peer_port;
          clog<<"客户端已连接"<<endl;
          //6.进行循环读写
          while(1)
          {
            string req;
            //7. 读取请求，读取失败则结束循环
            bool ret = new_sock.Recv(&req);
            if(!ret){
              clog<<"[client "<<peer_addr<<": "<<peer_port;
              clog<<"客户端关闭"<<endl;
              new_sock.Close();
              break;
            }
            //8.根据请求计算响应
            string resp;
            handler(req,&resp);
            //9.写回响应
            new_sock.Send(resp);
            clog<<"[client "<<peer_addr<<": "<<peer_port;
            clog<<"req "<<req<<endl;
            clog<<"resp "<<resp<<endl;
          }
        }
        return true;
    }
 private:
    TcpSocket _listen_sock;
    string _ip;
    uint16_t _port;
};
