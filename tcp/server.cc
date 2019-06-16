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
int main()
{
  dict.insert(make_pair("hehe","呵呵"));
  dict.insert(make_pair("hi","嗨"));
  dict.insert(make_pair("hello","你好"));
  TcpServer s("192.168.199.129",9090);
  s.Start(handler);
  return 0;
}
