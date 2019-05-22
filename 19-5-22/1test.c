#include<stdio.h>
#include<string.h>

int main()
{
  FILE* fd = fopen("myfile","w");
  if(!fd){
    perror("fopen\n");
  }
  const char* msg = "hello world";
  fwrite(msg,strlen(msg),1,fd);

  fclose(fd);
  return 0;
}
