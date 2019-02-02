/*
1065 A+B and C (64bit) （20 分）
Given three integers A, B and C in [−2
​63
​​ ,2
​63
​​ ], you are supposed to tell whether A+B>C.

Input Specification:
The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:
For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
*/
/*********
这题的关键是怎么处理溢出的情况。肯定是会溢出的，与其想着怎么样去避免溢出（如转换为字符串操作等一些做法），不如发掘一下溢出之后的特点。正溢出后
结果会变成负数，负溢出会变成正数。本题恰恰是利用这一特点而解。
*********/
#include <stdio.h>

int main()
{
  int t, cnt = 1;
  bool flag = false;
  scanf("%d", &t);
  
  long long a, b, c;
  
  while(t--){
    scanf("%lld%lld%lld", &a, &b, &c);
    
    long long res = a + b;
    
    if(a > 0 && b > 0 && res < 0){
      flag = true;
    }
    else if(a < 0 && b < 0 && res >= 0){
      flag = false;
    }
    
    else if(res > c){
      flag = true;
    }
    else{
      flag = false;
    }
    
    if(flag){
      printf("Case #%d: true\n", cnt);
    }
    else{
      printf("Case #%d: false\n", cnt);
    }
    cnt++;
  }
  return 0;
}
