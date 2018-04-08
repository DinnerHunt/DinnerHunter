//回文词 UVA401 2017.6.21

#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";					//储存A-Z和1-9的镜像字母
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
																			//存储输出结果
char r(char ch) {															//返回镜像字母的函数
  if(isalpha(ch)) return rev[ch - 'A'];										//是字母着从数组开头开始找
  return rev[ch - '0' + 25];												//数字则从第26个字母以后开始找
}

int main() {
  char s[30];														//储存接受数据
  while(scanf("%s", s) == 1) {			
    int len = strlen(s);											//获取长度
    int p = 1, m = 1;									//判断是否是回文和镜像
    for(int i = 0; i < (len+1)/2; i++) {		//循环判断		
      if(s[i] != s[len-1-i]) p = 0; 			// 如果前后不同 则不是回文串
      if(r(s[i]) != s[len-1-i]) m = 0; 			// 如函数返回值前后不同，则不是镜像串
    }
    printf("%s -- is %s.\n\n", s, msg[m*2+p]);
  }
  return 0;
}