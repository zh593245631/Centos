#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
//UDP版本的服务器
//服务器的基本工作流程
//1.初始化（服务器启动）
//2.进入一个主循环
//   a.读取客户端发来的"请求"(Request)
//   b.根据请求内容，计算生成"响应(Response)内容最核心
//   c.把响应数据返回客户端
int main()
{
  //1.先创建一个socket
  //AF_INET 是一个宏，表示使用ipv4协议
  //SOCK_DGRAM表示UDP协议
  int sock = socket(AF_INET,SOCK_DGRAM, 0);
  if(sock < 0)
  {
    perror("sock");
    return -1;
  } 
  //2.把当前的socket绑定到一个ip + 端口号
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  //ip 函数自己转换了网络字节序
  addr.sin_addr.s_addr = inet_addr("0.0.0.0");
  //端口号必须得先转换成网络字节序
  addr.sin_port = htons(9090);

  int ret = bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret < 0){
    perror("bind");
    return -1;
  }
  printf("server start ok!\n");
  //3.处理服务器收到的请求
  while(1)
  {
    //a)读取客户端的请求
    //面向数据报的函数接口
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    char buf[1024] = {0};
    ssize_t n = recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);
    if(n < 0){
      perror("recvform");
      continue;
    }
    buf[n] = '\0';
    printf("[%s:%d] buf: %s\n", inet_ntoa(peer.sin_addr),
                    ntohs(peer.sin_port),
                                buf);
    //b)根据请求计算响应
    //c)把响应写回客户端
    n = sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
    if(n < 0){
      perror("sendto");
      continue;
    }
    //netstat -anp |grep 9090
  }
  close(sock);
  return 0;
}
