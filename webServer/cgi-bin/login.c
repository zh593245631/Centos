#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define GET 0
#define POST 1
char* getcgidata(FILE* fp, char* requestmethod);
int main(void)
{
  printf("Content-type: text/html;charset=utf-8\r\n\r\n");
#if GET
  char username[64];
  char password[64];
  sscanf(getenv("QUERY_STRING"), "username=%[^&]&password=%s",username,password);

  printf("%s </br>%s</br>",username,password);
  printf(getenv("REQUEST_METHOD"));
  //printf("\n数据内容：%s<br/>",getenv("QUERY_STRING"));
  printf(getenv("REMOTE_ADDR"));
  //printf(getenv("GATEMAY_INTERFACE"));
#endif
#if POST
  char username[64];
  char password[64];
  char* req_method = getenv("REQUEST_METHOD");
  char* input = getcgidata(stdin, req_method);
  printf("%s<br/>",input);
  int j = 0;
  int i = 0;
  for (i = 9; i < (int)strlen(input); i++  )
  {
    if ( input[i] == '&'  )
    {
      username[j] = '\0';
      break;

    } 
    username[j++] = input[i];

  }
  for ( i = 19 + strlen(username), j = 0; i < (int)strlen(input); i++  )
  {
    if ( input[i] == '&'  )
    {
      password[j] = '\0';
      break;

    } 
    password[j++] = input[i];

  }
  password[j] = '\0';
  printf("Your Username is %s<br>Your Password is %s<br>\n", username, password);
  if(strcmp(username,"root")&&strcmp(password,"1234")){
     char message[1024];
     sprintf(message, "%s<body>\r\n", message);
     sprintf(message, "%s 输入错误\r\n", message);
     sprintf(message, "%s <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>", message);
     printf(message, "%s<hr><h3>不能为空<h3></body>", message);
  }
  
#endif
  return 0;
}
char* getcgidata(FILE* fp, char* requestmethod)
{
  char* input;
  int len;
  int size = 1024;
  int i = 0;
  if (!strcmp(requestmethod, "GET"))
  {
    input = getenv("QUERY_STRING");
    return input;

  }
  else if (!strcmp(requestmethod, "POST"))
  {
    len = atoi(getenv("CONTENT_LENGTH"));
    input = (char*)malloc(sizeof(char)*(size + 1));
    if (len == 0)
    {
      input[0] = '\0';
      return input;

    }
    while(1)
    {
      input[i] = (char)fgetc(fp);
      if (i == size)
      {
        input[i+1] = '\0';
        return input;

      }
      --len;
      if (feof(fp) || (!(len)))
      {
        i++;
        input[i] = '\0';
        return input;

      }
      i++;

    }

  }
  return NULL;
}
