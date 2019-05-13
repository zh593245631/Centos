#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
//input 表示切分命令
//output 表示切分结果 字符串数组
//返回值表示output 中包含了几个有效元素
int Split(char inptr[], char* output[])
{
 //strtok 来实现
  char* p = strtok(inptr," "); 
  int i = 0;
  while(p!=NULL)
  {
    //printf("%s\n",p);
    output[i] = p;
    p = strtok(NULL," ");
  }
  output[i] = NULL;
  return i;
}
int main()
{
  while(1)
  {
    //1.打印提示符
    printf("[z593245631@localhost]");
    fflush(stdout);
    //2.用户输入一个命令
    char command[1024] = {0};
    gets(command);//一次一行
    //3.解析命令，把要执行哪个程序识别出来，
    //命令行参数 字符串切分
    //切分结果是一个字符串数组
    char* argv[1024] = {0};
    Split(command,argv);
  }    
  return 0;
}
