#include"mysql.hpp"
#include"mysql2.hpp"
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
  char s[64];
  char *info=NULL;
  int lenstr=0;
  /*
   * Get the data by post method from index.html
   */
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"username=%[^&]&password=%[^&]&sd=%[^&]",user,passwd,s);
  free(info);

  string username = user;
  string password = passwd;
  string sd = s;
  Mysql mysql;
  mysql.ConnectDatabase();
  Mysql2 mysql2;
  mysql2.ConnectDatabase();
  string dbpass;
  if(mysql.QueryDatabase(username,&dbpass)){
       body = "<body>\r\n\
                该用户名已被注册\r\n\
               <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>";
  }
  else if(sd == "bhhhlsyzz"){
       mysql.InsertData(username,password);
       mysql2.InsertData(username,password);
       body = "<body>\r\n\
              注册成功\r\n\
               <a href=\"http://212.129.243.64/\">返回登陆</a>";
  }
  else{
      body = "<body>\r\n\
              身份认证失败\r\n\
              <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>";
  }
  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
  return 0;
} 
