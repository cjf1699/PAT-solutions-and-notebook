/*
1011 A+B 和 C （15 分）
给定区间 [−2
​31
​​ ,2
​31
​​ ] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。

输入格式：
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。

输出格式：
对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。

输入样例：
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
/*******
"A+B"系列的第一道题。取值范围较小，用长整型long long 就可以搞定。此外，本题并不需要使用数组进行存储，这也是前期做题时的一个误区，总是倾向于先存后算，
实际则完全可以边读入边计算，节省空间。
*******/
#include <stdio.h>
 
int main()
{
    int T;
    long long a[10] = {0}, b[10] = {0}, c[10] = {0};
     
    scanf("%d", &T);
     
    for(int i=0; i<T; i++){
        scanf("%ld%ld%ld", &a[i], &b[i], &c[i]);
    }
     
    for(int i=0; i<T; i++){
        if(a[i] + b[i] > c[i]){
            printf("Case #%d: true\n", i+1);
        }
        else{
            printf("Case #%d: false\n", i+1);
        }
    }
    return 0;
}
