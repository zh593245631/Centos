#include"mysql3.hpp"
#include<iostream>
using namespace std;

int main()
{
  string id,title,data;
  char* message[4][3];
  Mysql3 mysql;
  mysql.ConnectDatabase();
  mysql.QueryDatabase(message);
#if 1
  for(int i = 0; i<4; ++i)
  {
    for(int j = 0; j<3; ++j)
    {
      cout<<message[i][j];
    }
    cout<<endl;
  }
#endif
  return 0;
}
