#include<iostream>
#include"tcp_server.hpp"
#include<unordered_map>

using namespace std;

unordered_map<string,string> dict;
void handler(const string& req, string* resq)
{
  auto it = dict.find(req);
  if(it == dict.end())
  {
    *resq = "未找到";
    clog<<*resq<<endl;
    return;
  }
  *resq = it->second;
    clog<<*resq<<endl;
}
int main(int argc, char* argv[])
{
  if(argc != 3){
    printf("请输入 [ip] [port]\n");
    return 0;
  }
  dict.insert(make_pair("hehe","呵呵"));
  dict.insert(make_pair("hi","嗨"));
  dict.insert(make_pair("hello","你好"));
  TcpServer s(argv[1],atoi(argv[2]));
  s.Start(handler);
  return 0;
}
