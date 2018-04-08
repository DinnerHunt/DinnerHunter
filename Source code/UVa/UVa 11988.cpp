//UVa 破损的键盘 Broken Keyboard
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int last,cur,next[maxn];		//数字数组储存下一个数的位置
char s[maxn];

int main(){
	while(scanf("%s",s+1)==1){
		int n = strlen(s+1);
		last = cur = 0;
		next[0]=0;

		for(int i=1;i<=n;i++){
			char ch = s[i];
			if(ch == '[') cur=0;
			if(ch == ']') cur =last;
			else {
				next[i] = next[cur];	//i位置的下一个位置是指标的位置
				next[cur] = i;			
				if(cur == last ) last =i;
				cur = i;
			}
		}
		for(int i =next[0];i!=0;i=next[i])
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}