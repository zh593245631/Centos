#include<stdio.h>
#include<unistd.h>

int count = 0;
int main()
{
  pid_t ret = fork();
  if(ret>0)
  {
    count = 100;
    printf("father: %p   %d\n",&count,count);
  }
  else if(ret == 0)
  {
    sleep(1);
    printf("chirld: %p   %d\n",&count,count);
  }
  else{
    printf("fork");
  }
  return 0;
}
