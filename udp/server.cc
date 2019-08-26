#include"udp_server.hpp"
#include<iostream>

using namespace std;

void handler(const string& req, string* resp)
{
  *resp = req;
}
int main()
{
  udp_server server("0.0.0.0",9999);
  server.Start(handler);
  return 0;
}
