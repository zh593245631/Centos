#include"tcp_pthread_server.hpp"
#include<string>
using namespace std;

void HttpProcess(string& req, string* resp)
{
 string first_line = "HTTP/1.0 200 OK\n";
 string body = "<html><div><h1>hello world</h1></div></html\n";
#if 0
 string body = "<html lang=\"zh-cn\">\
                <!测试 test>\
                <body bgcolor=\"White\">\
                <div>\
                <br/>\
                <h1 align=\"center\">hehe</h1>\
                <hr/>\
                <br/>\
                <p style = \"background-color:Red\">Hello World</p>\
                <hr/>\
                <p style = \"front-family:arial;color:yellow;front-size:20px;\">HAHA.</p>\
                <a href=\"http://ww.w3school.com.cn\">w3school</a>\
                </div>\
                <img src=\"test.jpg\" width=\"104\" height=\"142\" />\
                </body>\
                </html>\n";
#endif
 string header = "Content-Type: text/html\ncharset: gbk\nContent-Length:"
            +to_string(body.size())+"\n\n";
 *resp = first_line + header + body;
 //service firewalld stop 关闭防火墙 #centos 7
 //service firewalld status
}
int main()
{
  TcpPthreadServer server("0.0.0.0",9090);
  server.Start(HttpProcess);
  return 0;
}
