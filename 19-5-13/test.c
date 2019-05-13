#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
//  int i = 0;
//  for(; env[i]; i++)
//  {
//    printf("%s\n",env[i]);
//  }
  //extern char **environ;

  //int i = 0;
  //for(;environ[i]; i++)
  //{
  //  printf("%s\n",environ[i]);
  //}
  printf("%s\n",getenv("PATH"));
  return 0;
}
