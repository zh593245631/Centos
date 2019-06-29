#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
  int a = 0; 
  int b = 0;
  sscanf(argv[1],"%d%d",&a,&b);
  int ans = a+b;
  cout<<"Content-Type: text/html\n\n";
  string body = "<html lang=\"zh-cn\">\
                <!测试 test>\
                <body bgcolor=\"White\">\
                <div>\
                <br/>\
                <h1 align=\"center\">在线学习交流</h1>\
                <hr/>\
                <p>ans</p>\
                <br/>\
                <p style = \"background-color:Red\">Hello World</p>\
                <hr/>\
                <p style = \"front-family:arial;color:yellow;front-size:20px;\">HAHA.</p>\
                <a href=\"http://ww.w3school.com.cn\">w3school</a>\
                </div>\
                <image src=\"test.jpg\"/></image>\
                </body>\
                </html>\n";
 cout<<body;
  return 0;
}
