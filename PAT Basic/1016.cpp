/*
1016 部分A+B （15 分）
正整数 A 的“D
​A
​​ （为 1 位整数）部分”定义为由 A 中所有 D
​A
​​  组成的新整数 P
​A
​​ 。例如：给定 A=3862767，D
​A
​​ =6，则 A 的“6 部分”P
​A
​​  是 66，因为 A 中有 2 个 6。

现给定 A、D
​A
​​ 、B、D
​B
​​ ，请编写程序计算 P
​A
​​ +P
​B
​​ 。

输入格式：
输入在一行中依次给出 A、D
​A
​​ 、B、D
​B
​​ ，中间以空格分隔，其中 0<A,B<10
​10
​​ 。

输出格式：
在一行中输出 P
​A
​​ +P
​B
​​  的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/
/*****
这道题设计处理一个整数的各个位的问题。同样无需繁琐地先记录数字出现地次数，然后调用pow()函数来计算和，完全可以在遍历过程中累加地方式，即每遇到满足条件
的位，就将原来的和乘10,再加上此位数。
另外需要注意的就是题目中数值的取值范围，需要用long long或字符串类型存储。
*****/
#include <stdio.h>
#include <string.h>
#include <math.h>
 
long long getP(char a[], int d){
    int len = strlen(a);
    int cnt = 0;
    for(int i=0; i<len; i++){
        if(a[i]-'0' == d){
            cnt++;
        }
    }
    long long p = 0;
    for(int i=0; i<cnt; i++){
        p += pow(10, i) * d;
    }
     return p;
}
 
int main()
{
    int da, db;
    long long pa, pb;
    char a[11], b[11];
     
    scanf("%s%d%s%d", a, &da, b, &db);
     
    pa = getP(a, da);
    pb = getP(b, db);
     
    printf("%lld\n", pa+pb);
    return 0;
     
}
