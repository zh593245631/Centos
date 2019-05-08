#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//env 也是一个字符串数组
//当前的环境变量
//env数组中也有一个结束标记 NULL
//main 函数有三种形式
//1.没参数
//2. int argc char* argv[]
//3. int argc char* argv[], char* env[]
int main(int argc, char* argv[], char* env[])
{
  (void)argc;
  (void)argv;
  (void)env;
  char* result = getenv("PATH");
  printf("%s\n",result);
  return 0;
}
