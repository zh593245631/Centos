#include"tcp_pthread_server.hpp"
#include<string>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

void HttpProcess(string& req, string* resp)
{
 string first_line = "HTTP/1.0 200 OK\n";
 //string body = "<html><div><h1>hello world</h1></div></html\n";
 string body = "<html lang=\"zh-cn\">\
                <!测试 test>\
                <body bgcolor=\"Red\">\
                <div>\
                <br/>\
                <h1 align=\"center\">hehe</h1>\
                <hr/>\
                <br/>\
                <p>哈哈</p>\
                <hr/>\
                <a href=\"http://www.w3school.com.cn\">This is a link</a>\
                </div>\
                <img src=\"test.jpg\" width=\"104\" height=\"142\" />\
                </body>\
                </html>\n";
 string header = "Content-Type: text/html\ncharset: gbk\nContent-Length:"
            +to_string(body.size())+"\n\n";
 //srand(time(NULL));
 //int a = rand()%10;
 //string c = "Cookie: hehe";
 //char d = a + '0';
 //c += d;
 //c += "\n\n";
 //string header = "Location: https://blog.csdn.net/qq_43634001/article/details/91398204\n" + c;
 *resp = first_line + header + body;
 //service firewalld stop 关闭防火墙 #centos 7
 //service firewalld status
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
