#include"udp_client.hpp"
#include<iostream>

using namespace std;

int main()
{
  udp_client client("127.0.0.1",9999);
  while(1)
  {
    string req;
    cout<< "please write :"<<flush;
    cin>>req;
    client.Send(req);
    string resp;
    client.Recv(&resp);
    cout<<"server said:"<<resp<<endl;
  }
  return 0;
}
