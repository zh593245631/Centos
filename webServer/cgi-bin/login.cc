#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<iostream>
using namespace std;
int main(void)
{
  //string first_line = "HTTP/1.0 200 OK\n";
  string header = "Content-type: text/html;charset=utf-8\r\n\r\n";
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
  if(username == "root"&& password == "1234"){
    //cout<<"success"<<endl;
    sleep(1);
    body = "<meta http-equiv=\"Refresh\" content=0;URL=\"http://212.129.243.64/1.html\">"; 
  }
  else{
         body = "<body>\r\n\
                输入错误\r\n\
                <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>";
  }
  //body += username;
  //body += password;
  cout<<header+body<<endl;
  return 0;
} 
