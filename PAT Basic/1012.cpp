/*
1012 数字分类 （20 分）
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A
​1
​​  = 能被 5 整除的数字中所有偶数的和；
A
​2
​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n
​1
​​ −n
​2
​​ +n
​3
​​ −n
​4
​​ ⋯；
A
​3
​​  = 被 5 除后余 2 的数字的个数；
A
​4
​​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A
​5
​​  = 被 5 除后余 4 的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A
​1
​​ ~A
​5
​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
*/
#include <stdio.h>

int main()
{
  int n, a[1000];

  scanf("%d", &n);

  int a1 = 0, a2 = 0, a3 = 0, a5 = 0, cnt = 0;
  bool add_flag2 = 1, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
  double a4 = 0.0;

  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);

    if(a[i] % 5 == 0 && a[i] % 2 == 0){
      flag1 = 1;
      a1 += a[i];
    }
    else if(a[i] % 5 == 1){
      flag2 = 1;
      if(add_flag2){
        a2 += a[i];
        add_flag2 = 0;
      }
      else{
        a2 -= a[i];
        add_flag2 = 1;
      }
    }
    else if(a[i] % 5 == 2){
      flag3 = 1;
      a3++;
    }
    else if(a[i] % 5 == 3){
      flag4 = 1;
      a4 += a[i];
      cnt++;
    }
    else if(a[i] % 5 == 4){
      flag5 = 1;
      if(a[i] > a5){
        a5 = a[i];
      }
    }
  }

  if(flag1) printf("%d ", a1); else printf("N ");
  if(flag2) printf("%d ", a2); else printf("N ");
  if(flag3) printf("%d ", a3); else printf("N ");
  if(flag4) printf("%.1f ", a4/cnt); else printf("N ");
  if(flag5) printf("%d\n", a5); else printf("N\n");

  return 0;
}

