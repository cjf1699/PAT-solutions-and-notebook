/*
1010 一元多项式求导 （25 分）
设计函数求一元多项式的导数。（注：x
​n
​​ （n为整数）的一阶导数为nx
​n−1
​​ 。）

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
*/
#include <stdio.h>

int main()
{
  int a[1010] = {0};
  int k ,e, count = 0;
  while(scanf("%d%d", &k, &e) != EOF){
    a[e] = k;
  }
  a[0] = 0;
  for(int i=1; i<=1000; i++){
    a[i-1] = a[i] * i;
   // a[i] = 0;
    if(a[i-1] != 0) count++;

  }
  if(count == 0) printf("0 0");
  else{
    for(int i=1000; i>=0; i--){
        if(a[i] != 0){
            printf("%d %d", a[i], i);
            count--;
            if(count != 0) printf(" ");
        }
    }
  }

  return 0;
}
/***
本题其实还有更简洁的写法，无需使用数组存储，直接判断每一组“系数--指数对”，然后输出即可。要注意的有两点，一个是可以利用while...EOF的方式，判断输入
是否结束，一个是好多题都涉及到特判，比如此题当求导结果没有非零项时，要输出“0 0”（输入为常数时）
***/
#include <stdio.h>

int main()
{
  int a[1010] = {0};
  int k ,k1, e, e1, count = 0;
  while(scanf("%d%d", &k, &e) != EOF){
    k1 = e * k;
    e1 = e - 1;
    if(k1){
      count++;
      if(count == 1){
        printf("%d %d", k1, e1);
      }
      else{
        printf(" %d %d", k1, e1);
      }
    }
  }
  if(!count){
    printf("0 0\n");
  }
  else{
    printf("\n");
  }
  return 0;
}
