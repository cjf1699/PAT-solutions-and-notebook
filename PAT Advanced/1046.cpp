/*
1046 Shortest Distance （20 分）
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10
​5
​​ ]), followed by N integer distances D
​1
​​  D
​2
​​  ⋯ D
​N
​​ , where D
​i
​​  is the distance between the i-th and the (i+1)-st exits, and D
​N
​​  is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (≤10
​4
​​ ), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10
​7
​​ .

Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/
/*******
这道题要注意的是，如何直接计算的话可能会超时，因为数量较大，N M都是10000以上的量级，因此要转换一种思路，变为查询的方法。用一个数组保存从第一个节点
到第i个节点距离（可以在输入时就计算累加得到），然后对于待求的节点对，相减即可得到。
*******/
#include <stdio.h>

int input[100002];
int dist[100002];
int result[10000];

int main()
{
  int n, m, total = 0;
  int e1, e2;
  
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &input[i]);
    total += input[i];
    if(i == 1){
      dist[i] = 0;
    }
    else{
      dist[i] = dist[i-1] + input[i-1];
      // for(int j=1; j<i; j++){
      //   dist[i] += input[j];      // dist[i]表示从第一个节点到第i个节点顺时针方向的距离
      // }
    }
  }
  
  scanf("%d", &m);
  
  for(int i=0; i<m; i++){
    scanf("%d%d", &e1, &e2);
    
    if(e1 > e2){
      int temp = e2;
      e2 = e1;
      e1 = temp; 
    }
    result[i] = (dist[e2] - dist[e1]) < (total - (dist[e2] - dist[e1])) ? (dist[e2] - dist[e1]): (total - (dist[e2] - dist[e1]));
  }
  
  for(int i=0; i<m; i++){
    printf("%d\n", result[i]);
  }
  
  return 0;
}
