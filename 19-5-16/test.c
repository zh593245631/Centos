#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

typedef void (*FUNC)(void *);
void func(void* arg)
{
  printf("%s\n",arg);
}

void process_create(pid_t* pid, void* func,char* arg)
{
 *pid = fork();
 
 if(*pid<0){
   perror("error");
   exit(-1);
 }
 else if(*pid == 0){
   //child
      FUNC funct = (FUNC)func;
      funct(arg);
      sleep(5);
}
 else{
   //father
   pid_t ret = wait(NULL);
   printf("chirld: %d\n",ret);
 }
}
int main()
{
  pid_t pid;
  char* arg = "child";
  
  process_create(&pid,func,arg);
  return 0;
}
