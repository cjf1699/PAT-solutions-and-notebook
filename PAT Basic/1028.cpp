/*
1028 人口普查 （20 分）
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10
​5
​​ ]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
/*
这道题。。一开始蠢死了，居然没有给ans_max和ans_min赋初值。。。。输入格式居然还忘记斜杠了。
学到的是，注意是否需要特判，比如这道题如果所有输入日期都不合法（极端情况），就要特判输出0，否则会格式错误。
也侧面说明了格式错误不一定就是多输出空格、回车。
*/
#include <stdio.h>

struct person{
  char name[6];
  int year;
  int month;
  int day;
}ans, ans_max, ans_min;

const int curr_year = 2014;
const int curr_month = 9;
const int curr_day = 6;

int valid(struct person a);
int judge(struct person a, struct person b);

int main()
{
  int n, cnt = 0;
  scanf("%d", &n);
  
  ans_max.year = 2015;
  ans_min.year = 1813;
  
  for(int i=0; i<n; i++){
    scanf("%s %d/%02d/%02d", ans.name, &ans.year, &ans.month, &ans.day);
    
    int isValid = valid(ans);
    cnt += isValid;
    
    if(!isValid){
      continue;
    }
    
    int result;
    
    result = judge(ans, ans_max);
    if(result > 0){
      ans_max = ans;
    }
    
    result = judge(ans, ans_min);
    if(result < 0){
      ans_min = ans;
    }
  }
  if(!cnt){
    printf("0\n");
  }
  else{
    printf("%d %s %s\n", cnt, ans_max.name, ans_min.name);
  }
  
  return 0;
}

int valid(struct person a){
  if(a.year > 2014 || 
     a.year < 1814 || 
    (a.year == 2014 && a.month > 9) ||
    (a.year == 2014 && a.month == 9 && a.day > 6) ||
    (a.year == 1814 && a.month < 9) ||
    (a.year == 1814 && a.month == 9 && a.day < 6)){
    return 0;
  }
  return 1;
}

int judge(struct person a, struct person b){
  if(a.year < b.year ||
     (a.year == b.year && a.month < b.month) ||
     (a.year == b.year && a.month == b.month && a.day < b.day)){
       return 1;
     }
  return -1;
}
