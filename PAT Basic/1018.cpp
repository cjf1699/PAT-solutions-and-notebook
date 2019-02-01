/*
1018 锤子剪刀布 （20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：


现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10
​5
​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/
/*******
这题涉及字符数据的换行输入，因此要使用getchar()在适当的地方吸收空格。解此题时，我采用了if else if...的方法，不够简洁。《晴神宝典》上给的解法提供
了一种很好的思路，首先建立字符到数字的映射，将 B C J 对应为0,1,2，这种做法很朴素，因为显然数字能够更方便的参与各种运算。然后，由于锤子剪子布是一个
“循环相克”的问题，因此可以使用取模的思想来判断输赢的条件 , 如甲为k1, 乙为k2, 则(k1+1) % 3 == k2为甲赢乙输的条件。
*******/
#include <stdio.h>

int main()
{
  int jia_c = 0, jia_j = 0, jia_b = 0, yi_c = 0, yi_j = 0, yi_b = 0, ping = 0;
  int n;
  char jia, yi;

  scanf("%d", &n);
  getchar();
  for(int i=0; i<n; i++){

    scanf("%c %c", &jia, &yi);
    getchar();
    if(jia == 'C' && yi == 'J') jia_c++;
    else if(jia == 'J' && yi == 'B') jia_j++;
    else if(jia == 'B' && yi == 'C') jia_b++;

    else if(yi == 'C' && jia == 'J') yi_c++;
    else if(yi == 'J' && jia == 'B') yi_j++;
    else if(yi == 'B' && jia == 'C') yi_b++;

    else if(yi == jia) ping++;
  }

  printf("%d %d %d\n", jia_b+jia_c+jia_j, ping, n-ping-(jia_b+jia_c+jia_j));
  printf("%d %d %d\n", yi_b+yi_c+yi_j, ping, n-ping-(yi_b+yi_c+yi_j));

  char max_jia, max_yi;
  if(jia_j >= jia_b && jia_j >= jia_c)  max_jia = 'J';
  if(jia_c >= jia_b && jia_c >= jia_j)  max_jia = 'C';
  if(jia_b >= jia_c && jia_b >= jia_j)  max_jia = 'B';

  if(yi_j >= yi_b && yi_j >= yi_c)  max_yi = 'J';
  if(yi_c >= yi_b && yi_c >= yi_j)  max_yi = 'C';
  if(yi_b >= yi_c && yi_b >= yi_j)  max_yi = 'B';

  printf("%c %c\n", max_jia, max_yi);
  return 0;
}
