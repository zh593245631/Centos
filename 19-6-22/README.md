JSON -> JavaScript -> TypeScript(MS) JS的超集
                      Flutter(谷歌)移动端开发框架

Json 是一种非常重要的序列化/反序列化的方式i
Json 的优点：直观，方便调试
Json 的缺点：效率低 (东西多占用带宽)

google protobuf
二进制的方式序列化

Http协议

fiddler 抓包工具

浏览器                        服务器
       <---->  fidler <------>
-----         -----           -----


HTTP 协议格式
请求
1.首行(空格分隔)
  a)方法（GET/POST/PUT/DELETE/HEAD）获取发送
  b)url
  c)http 版本号，HTTP/1.1(当前最常见的版本号)
2.头部信息(header)
  若干行
  每行是一个键值对，k和v用：分割
3.空行
  header的结束
4.请求体人（body)
  空行后面的内容
  一般来说GET请求不带 body POST/PUT请求带 body
响应
1.首行
  a)版本号
  b)状态码
  c)状态码的描述信息
2.




#*#*#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*
1.HTTP 协议中常见的方法有哪些
2.GET 和 POST 的区别
  GET 往往把参数放到 query_string 中
  POST 把参数放在 body 中
3.说说常见的 HTTP 状态码有哪些,分别是哪些含义
  200 OK
  302 Found 重定向 /303 See Other 重定向 Location 字段表示重定向到那个
  403 Forbidden 用户没有权限访问
  404 Not Found 没有找到指定的资源
  502 Bad Gateway 服务器挂了
  504 Gateway Timeout 服务器响应超时

  2* 请求成功
  3* 重定向
  4* 客户端出现错误
  5* 服务器出现错误

  w3school
  常用 header
  Content-Type ----- 描述了 body 部分数据格式是什么数据类型test/html等
  Content-Length --- body 的长度
  Host ------------- 告诉服务器资源在哪个端口上
  User-Agent ------- 声明用户的操作系统和浏览器版本信息
  referer ---------- 当前页面是从哪个页面跳过来的
  location --------- 搭配 3xx 状态码使用，告诉客户端接下来要去哪里访问
  Cookie ----------- 是一个保存在浏览器端的字符串，字符串的含义是由程序
                     员内部约定的，外部的用户一般是看不懂含义的，
                     Cookie 中最常见的内容是用户的身份信息 session id


  
















