#include <stdio.h>
#include<unistd.h>
int main()
{
  const char* a ="/~\\"; 
  char buff[1024] = {0};
  int i = 0;
  for( ; i<100; ++i)
  {
    buff[i] = '#';
    // \n 表示换行，另起一行，光标来行首
    // \r 表示回车，不另起一行，光标来行首
    printf("[%d%%][%c][%s]\r",i, a[i%3], buff);
    fflush(stdout);
    //单位是秒
    //sleep(1);
    usleep(500*1000);
  }
  return 0;
}
