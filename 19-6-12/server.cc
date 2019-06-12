#include<iostream>
#include"udp_server.hpp"
using namespace std;

int main()
{
  UdpServer s;
  s.Start("0.0.0.0",9090);
  return 0;
}
