#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
  const char* msg0 = "hehe printf\n";
  const char* msg1 = "hehe fwrite\n";
  const char* msg2 = "hehe write\n";

  printf("%s",msg0);
  fwrite(msg1,strlen(msg1),1,stdout);
  write(1,msg2,strlen(msg2));

  fork();
  return 0;
}
