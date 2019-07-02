#include<iostream>
#include<stdio.h>
using namespace std;

int main(int arac, char** argv)
{
 int a = 0; 
 int b = 0;
 sscanf(argv[1],"%d%d", &a,&a);
 string body = "hello\n";
 cout<<"Content-Type: text/html\n\n";
 cout<<body;
  return 0;
}
