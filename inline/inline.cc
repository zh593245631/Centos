inline int Add(int a, int b)
{
     return a + b;

}
int main()
{
     int num1 = 1;
     int num2 = 2;
     int myNum = Add(num1, num2);

}
//这样的代码内联之后大概就是
//int main()
//{
//   int num1 = 1;
//      int num2 = 2;
//         int myNum = num1 + num2;
//         }
//
//}
