//环状序列 UVa10082	2017.6.15

#include<stdio.h>
#include<string.h>
#define maxn 105

// 环状串s的表示法p是否比表示法q的字典序小
int less(const char* s, int p, int q) {
  int n = strlen(s);				//获取数组长度
  for(int i = 0; i < n; i++)		//循环从数组的p,和q比较，如果不相等则退出循环，
    if(s[(p+i)%n] != s[(q+i)%n])
      return s[(p+i)%n] < s[(q+i)%n];//返回布尔值
  return 0; // 相等
}

int main() {
  int T;
  char s[maxn];				//存储读取的数组
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);				//获取字符串
    int ans = 0;				//重置最小位置
    int n = strlen(s);		
    for(int i = 1; i < n; i++)
      if(less(s, i, ans)) ans = i;		//如果为真，则i的位置小于ans；
    for(int i = 0; i < n; i++)	//从最小位置循环输出
      putchar(s[(i+ans)%n]);
    putchar('\n');
  }
  return 0;
}