#include"tcp_pthread_server.hpp"
#include<string>
#include<string.h>
using namespace std;

void HttpProcess(string& req, string* resp)
{
 string first_line = "HTTP/1.0 200 OK\n";
 string body = "<html><div>hello world</div></html>\n";
 string header = "Content-Type: text/html\nContent-Length:"
               +to_string(body.size())+"\n\n";
 *resp = first_line + header + body;
 //service firewalld stop 关闭防火墙 #centos 7
 //service firewalld status
 //string header = "Location: http://www.sogou.com\n";
#if 0
     char buf[1024] = {0};
     const char* hello = "<h1>hello world</h1>";

     sprintf(buf, "HTTP/1.0 200 OK\nContent-Length:%lu\n\n%s", strlen(hello), hello);
     *resp = buf;
#endif

}
int main()
{
  TcpPthreadServer server("0.0.0.0",9090);
  server.Start(HttpProcess);
  return 0;
}
