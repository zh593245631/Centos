#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<pwd.h>
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
    output[i] = p;
    p = strtok(NULL," ");
    i++;
  }
  output[i] = NULL;
  return i;
}

void _create(char* argv[])
{
  pid_t ret = fork();
  if(ret == 0){
    //子进程
    if(argv[0])
      execvp(argv[0],argv);
    exit(-1);
  }
  else if(ret>0){
    //父进程
    wait(NULL);
  }
  else{
    //错误
    perror("error");
  }
}
//当前目录文件
char* Pwd()
{
  //char* pwd;
  char* dir = NULL;
  dir = (char*)get_current_dir_name();
  int len = strlen(dir);
  int i = 0;
  while(1)
  {
   if(dir[len-1-i] == '/')break;
   ++i;
  }
  //pwd = dir+len-i;
  //printf("%s\n",pwd);
  return dir+len-i;
}
int main()
{
  while(1)
  {
    //获取当前文件夹名
    char* pwd1 = Pwd();
    //获取当前用户
    struct passwd * pwd2; 
    pwd2 = getpwuid(getuid());
    //1.打印提示符
    printf("[%s@localhost %s]$",pwd2->pw_name,pwd1);
    fflush(stdout);
    //2.用户输入一个命令
    char command[1024] = {0};
    gets(command);//一次一行
    //3.解析命令，把要执行哪个程序识别出来，
    //命令行参数 字符串切分
    //切分结果是一个字符串数组
    char* argv[1024] = {0};
    Split(command,argv);
    //4.创建子进程去执行替换程序
    //cd命令特殊处理
    if(strcmp(argv[0], "cd")== 0){
      chdir(argv[1]);
    }
    else
    _create(argv);
  }    
  return 0;
}
