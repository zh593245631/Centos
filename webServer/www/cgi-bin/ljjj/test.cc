
#include <iostream>  
#include <sstream>  
#include <memory>  
#include <string>  
#include <stdexcept>  
      
using namespace std;  
      
#include <mysql_connector_c/jdbc/mysql_connection.h>  
#include <mysql_connector_c/jdbc/mysql_driver.h>  
#include <mysql_connector_c/jdbc/cppconn/driver.h>  
      
using namespace sql;  
      
#define DBHOST "tcp://localhost:3306"  
#define USER "root"  
#define PASSWORD "qwerdf123"  
      
int main() {
  Driver *driver;  
  Connection *conn;  
  driver = get_driver_instance();  
  conn = driver->connect(DBHOST, USER, PASSWORD);  
  conn->setAutoCommit(0);  
  cout<<"DataBase connection autocommit mode = "<<conn->getAutoCommit()<<endl;  
  delete conn;  
  driver = NULL;  
  conn = NULL;  
  return 0;  
}
