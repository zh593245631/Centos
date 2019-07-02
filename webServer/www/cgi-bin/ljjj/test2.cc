#include"mysql.hpp"
#include<iostream>

using namespace std;


int main()
{
  Mysql mysql;
  mysql.ConnectDatabase();
  string password;
  mysql.QueryDatabase("zzh",&password);
  cout<<mysql.InsertData("hehe","123456")<<endl;
  mysql.QueryDatabase("hehe",&password);
  cout<<password<<endl;

  return 0;
}
