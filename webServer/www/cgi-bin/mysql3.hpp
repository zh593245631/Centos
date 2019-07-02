#pragma once
#include <stdio.h>
#include <mysql/mysql.h>   
#include<string>
using namespace std;

class Mysql3
{
public:
    Mysql3()
    {
      mysql_init(&mysql); 
    }
    //连接数据库
    bool ConnectDatabase(
      const char host[] = "127.0.0.1",
      const char user[] = "root",
      const char passwd[] = "qwerdf123",
      const char db[] = "db",
      unsigned int port = 3306,
      const char *unix_socket = NULL,
      unsigned long client_flag = 0
      ){
      if (mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)){
                 return true;
      }
      else{
                 return false;
      }
     }

     ~Mysql3()
     {
        mysql_free_result(res);
        mysql_close(&mysql);
     }

//查询数据
bool QueryDatabase(char* message[4][3]){
      char query[150]; //查询语句
      //将数据格式化输出到字符串
       sprintf(query, "select * from Message");
      //设置编码格式
       mysql_query(&mysql, "set names gbk"); 

       if (mysql_query(&mysql, query)){
              return false;
       }
      res = mysql_store_result(&mysql);
      if (!res){
               return false;
       }
                       MYSQL_ROW column;
                       int i = 0;
                       while (column = mysql_fetch_row(res)){
                         message[i][0] = column[0];
                         message[i][1] = column[1];
                         message[i][2] = column[2];
                         ++i;
                    }
          return true;

}

//插入数据
bool InsertData(const string username, const string password){

    char query[150];    //查询语句
    sprintf(query, "insert into mager(username,password) values('%s','%s');",username.c_str(),password.c_str());
    if (mysql_query(&mysql, query)) {
           return false;
    }
    else{
           return true;
    }
}

//删除数据
bool DeleteData(const string& username)
{
  char query[150];    //查询语句
  sprintf(query, "delete from mager where username='%s';",username.c_str());
   
        if (mysql_query(&mysql, query)) {
             return false;
         }
         else{
             return true;
         }
}

//修改数据
bool modifydata(const string& username, const string& password){

   char query[150];    //查询语句
   sprintf(query, "update mager set username='%s'",username.c_str());
   sprintf(query, " where password = '%s'",password.c_str());
   if (mysql_query(&mysql, query)) {
       return false;
    }
   else{
       return true;
    }
}

private:
    MYSQL mysql;
    MYSQL_RES *res;     //行的一个查询结果集
};
