/*
1009 Product of Polynomials （25 分）
This time, you are supposed to find A×B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N
​1
​​  a
​N
​1
​​ 
​​  N
​2
​​  a
​N
​2
​​ 
​​  ... N
​K
​​  a
​N
​K
​​ 
​​ 

where K is the number of nonzero terms in the polynomial, N
​i
​​  and a
​N
​i
​​ 
​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N
​K
​​ <⋯<N
​2
​​ <N
​1
​​ ≤1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
*/
/*
这道题的0号测试点一直没过，上网查终于找到了原因，问题出在统计结果的非零项的个数上。在计算过程中不要试图去统计个数，因为
前面如果算上了一个非零项，那么后面可能计算出来一项正负相消了就又变成了0，还得减去。所以最好的方式就是全部算完之后再统计非零0数。
*/

#include <stdio.h>

double a[1001], b[1001], c[2001];
bool flag[2001] = {0};

int main()
{
  int ka, kb, expo, cnt = 0;
  double coff;

  scanf("%d", &ka);
  for(int i=0; i<ka; i++){
    scanf("%d%lf", &expo, &coff);
    a[expo] = coff;
  }

  scanf("%d", &kb);
  for(int i=0; i<kb; i++){
    scanf("%d%lf", &expo, &coff);
    b[expo] = coff;
  }


  for(int i=0; i<=1000; i++){
    
    if(a[i]){
      for(int j=0; j<=1000; j++){
        if(b[j]){
          c[i+j] += a[i] * b[j];
        }
      }
    }
  }
  
  for(int i=0; i<2001; i++){
    if(c[i]){
      cnt++;
    }
  }
  
  printf("%d", cnt);
  
  for(int i=2000; i>=0; i--){
    if(c[i]!=0.0)
      printf(" %d %.1lf", i, c[i]);
  }
  // printf("\n");
  return 0;
}
