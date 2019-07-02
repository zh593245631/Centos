#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<iostream>
using namespace std;
int main(void)
{
  string header;
  //string first_line = "HTTP/1.0 200 OK\n";
  string body;
  char user[64];
  char passwd[64];
  char *info=NULL;
  int lenstr=0;
  /*
   * Get the data by post method from index.html
   */
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"username=%[^&]&password=%[^&]",user,passwd);
  free(info);

  string username = user;
  string password = passwd;
  Mysql mysql;
  mysql.ConnectDatabase();
  string dbpass;
  if(mysql.QueryDatabase(username,&dbpass)){
       body = "<body>\r\n\
                该用户名已被注册\r\n\
               <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>";
  }
  else{
       mysql.InsertData(username,password);
       body = "<body>\r\n\
              注册成功\r\n\
               <a href=\"http://212.129.243.64/\">返回登陆</a>";
  }
  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
  return 0;
} 
