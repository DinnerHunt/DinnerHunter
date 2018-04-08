//P1203 坏掉的项链
//DinnerHunt
#include <cstdio>
#include <iostream>
using namespace std;
inline int max(int x ,int y){
	return x>y?x:y;
}
int ans,now,n,last;
string str;
void dfs(int pos,char ch,int d,int k){
	if(ch=='w'&&str[pos]!='w') ch = str[pos];
	if(pos==k||last==pos) return;
	if(str[pos]==ch||str[pos]=='w'||ch=='w'){
		now++;
		dfs((pos+d+n)%n,ch,d,k);
	}
    else
        last=(pos-d+n)%n;
}
int main(){
    scanf("%d",&n);
	cin >> str;
	for(int i=0;i<n;i++){
		last=(i+1)%n;
		now = 1;
		dfs((i+2+n)%n,str[(i+1)%n],1,(i+1)%n);
		if(last!=(i+1)%n){
            now++;
		    dfs((i+n-1)%n,str[i],-1,i);
        }
		ans = max(now,ans);
	}
	printf("%d",ans);
	return 0;
}