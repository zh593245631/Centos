#include<stdio.h>
#include<string.h>

int main()
{
  FILE* fd = fopen("myfile","r");
  if(!fd){
    perror("fopen error");
  }
  char buf[1024];
  fread(buf,1,11,fd);
  printf("%s\n",buf);
  fclose(fd);
  return 0;
}
