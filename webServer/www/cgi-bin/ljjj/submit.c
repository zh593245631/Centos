#include <stdio.h>
#include <string.h>
 
#define MAXBUFFER 2048
#define MAXLINE 1024
 
int main(int argc, char *argv[])
{
      int a, b;
        char body[MAXBUFFER], content[MAXLINE];
           int ret = sscanf(argv[1], "%d&%d", &a, &b);
           //int ret = 0;
                if(ret < 0 || ret != 2)
                {
                      //设置消息体
                          sprintf(body, "<html><title>add.action</title>");
                              sprintf(body, "%s<body bgcolor=""green"">\r\n", body);
                                  sprintf(body, "%s %s\r\n", body, "200");
                                      sprintf(body, "%s <p>%s: %s", body, "GET", "fail");
                                          sprintf(body, "%s <p>The addition\r\n", body);
                                              sprintf(body, "%s The parameter is wrong\r\n", body);
                                                  sprintf(body, "%s<hr><h3>The Tiny Web Server<h3></body>\r\n", body);
                                                   
                                                      //设置请求头
                                                          sprintf(content, "HTTP/1.1 %s\r\n", "GET");
                                                              sprintf(content, "%sContent-type: text/html\r\n", content);
                                                                  sprintf(content, "%sContent-length: %d\r\n", content, 
                                                                              (int)strlen(body));
                                                                                  sprintf(content, "%sEncoding:UTF-8\r\n\r\n", content);
                      //                                                              
                }
                  else
                  {
                        //设置消息体
                            sprintf(body, "<html><title>add.action</title>");
                                sprintf(body, "%s<body bgcolor=""green"">\r\n", body);
                                    sprintf(body, "%s %s\r\n", body, "200");
                                        sprintf(body, "%s <p>%s: %s", body, "GET", "success");
                                            sprintf(body, "%s <p>The addition\r\n", body);
                                                sprintf(body, "%s The answer of %d + %d = %d\r\n", body, a, b, a + b);
                                                    sprintf(body, "%s<hr><h3>The Tiny Web Server<h3></body>\r\n", body);
                                                     
                                                        //设置请求头
                                                            sprintf(content, "HTTP/1.1 %s\r\n", "GET");
                                                                sprintf(content, "%sContent-type: text/html\r\n", content);
                                                                    sprintf(content, "%sContent-length: %d\r\n", content, 
                                                                                (int)strlen(body));
                                                                                    sprintf(content, "%sEncoding:UTF-8\r\n\r\n", content);
                        //                                                              
                  }
                    printf("%s", content);
                      printf("%s", body);
                        fflush(stdout);
                          return 0;

}
