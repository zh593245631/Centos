#include<stdio.h>
#include<string.h>

int main()
{

  //const char* msg = "fwrite\n";
  const char* msg = "fwrite";
  fwrite(msg,strlen(msg),1,stdout);
  //printf("printf\n");
  printf("printf");
  //fprintf(stdout,"fprintf\n");
  fprintf(stdout,"fprintf");
  return 0;
}
