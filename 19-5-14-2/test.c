#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int val = 0;
int main()
{
  pid_t ret = fork();

  if(ret>0){
    val = 1;
    printf("father: %d,val: %d, %p\n",getpid(),val,&val);
    sleep(3);
  }
  else if(ret == 0){
    sleep(2);
    printf("chrild: %d,val: %d, %p\n",getpid(),val,&val);
  }
  else{
    perror("error\n");
  }
  return 0;
}
