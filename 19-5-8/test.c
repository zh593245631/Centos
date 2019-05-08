#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t ret = fork();
  if(ret>0){
    //father
    int count = 5;
    while(count--)
    {
      sleep(10);
    }
    printf("father: %d ret: %d\n",getpid(),ret);
  }else if(ret == 0){
    printf("chird: %d ret: %d\n", getpid(),ret);
  }
  else{
    perror("??");
  }
  return 0;
}
