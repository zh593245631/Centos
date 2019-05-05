//git add  commit   push
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  const char* a = "/~\\";
  char buf[103] = {0};

  memset(buf,' ',101);
  buf[101] = ']';
  buf[102] = '\0';
  int i = 0;
  for(; i<=100; i++)
  {
    buf[i] = '#';
    if(i<100)
    buf[i+1] = '>';
    printf(" \e[0;31m[%d%%]\e[1;33m[%c]\e[1;32m[%s\r",i,a[i%3],buf);
    fflush(stdout);
    usleep(500*1000);
  }
  printf("\ncomplete\n\e[0m");
  return 0;
}
