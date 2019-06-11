#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>

int main(int argc, char* argv[])
{
  //1.先去创建一个socket
  int sock = socket(AF_INET,SOCK_DGRAM,0);
  if(sock < 0){
    perror("socket");
    return -1;
  }
  //客户端一般不需要bind
  //如果没有bind，操作系统会随机分配一个端口号
  //如果是服务器程序不去bind就会导致每次启动服务端口号不一样
  //客户端没法连接
  //客户端bind的话会出问题
  //一个端口号只能被一个进程bind
  
  //2.准备好服务器的sockeaddr_in结构
  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(9090);

  //3.客户端直接发送数据即可
  while(1)
  {
   printf("请输入一段内容\n");
   char buf[1024] = {0};
   scanf("%s",buf);
   ssize_t n = sendto(sock,buf,strlen(buf),0,(sockaddr*)&server_addr,sizeof(server_addr));
   if(n < 0){
     perror("sendto\n");
     continue;
   }
   char buf_output[1024] = {0};
   recvfrom(sock,buf_output,sizeof(buf_output)-1,0,NULL,NULL);
   printf("server: %s\n",buf_output);
  }
  close(sock);
  return 0;
}
   
