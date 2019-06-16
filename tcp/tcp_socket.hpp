#pragma once
#include<iostream>
#include<string>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;

class TcpSocket{
 public:
    TcpSocket():_fd(-1){}
    TcpSocket(int fd):_fd(fd){}

    bool Socket(){
        _fd = socket(AF_INET,SOCK_STREAM,0);
        if(_fd < 0){
            cerr<<"socket";
            return false;
        }
        clog<<"open fd = "<<_fd<<endl;
        return true;
    }
    bool Close()const{
        close(_fd);
        clog<<"close fd = "<<_fd<<endl;
        return true;
    }

    bool Bind(const string& ip, uint16_t port)const
    {
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        addr.sin_port = htons(port);

        int ret = bind(_fd,(sockaddr*)&addr, sizeof(addr));
        if(ret < 0){
            cerr<<"bind false";
            return false;
        } 
        clog<<"bind success"<<endl;
        return true;
    }

    bool Listen(int num) const
    {
        int ret = listen(_fd, num);
        if(ret < 0)
        {
            cerr<<"listen false";
            return false;
        }
        clog<<"listen true"<<endl;
        return true;
    }
    bool Accept(TcpSocket* peer, string* ip = NULL, uint16_t* port = NULL)const
    {
        sockaddr_in peer_addr;
        socklen_t len = sizeof(peer_addr);
        int new_sock = accept(_fd,(sockaddr*)&peer_addr,&len);
        if(new_sock < 0){
            cerr<<"accept false";
            return false;
        }
        clog<<"accept fd = %d"<<_fd<<endl;
        peer->_fd = new_sock;
        if(ip!=NULL)
        {
            *ip = inet_ntoa(peer_addr.sin_addr);
        }
        if(port!=NULL)
        {
            *port = ntohs(peer_addr.sin_port);
        }
        return true;
    }

    bool Recv(string* buf) const
    {
        buf->clear();
        char tmp[1024*10] = {0};
        ssize_t read_size = recv(_fd, tmp, sizeof(tmp),0);
        if(read_size < 0){
            cerr<<"recv false";
            return false;
        }
        if(read_size == 0)
        return false;

        buf->assign(tmp,read_size);
        return true;
    }

    bool Send(string& buf)const
    {
        ssize_t write_size = send(_fd,buf.data(),buf.size(),0);
        if(write_size < 0)
        {
            cerr<<"send false";
            return false;
        }
        return true;
    }

    bool Connect(string& ip, uint16_t port)
    {
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        addr.sin_port = htons(port);
        int ret = connect(_fd,(sockaddr*)&addr, sizeof(addr));
         
        if(ret < 0){
            cerr<<"connect false";
            return false;
        }
        return true;
    }

    int GetFd()const
    {
        return _fd;
    }
 private:
    int _fd;
};
