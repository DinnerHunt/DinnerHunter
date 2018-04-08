#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1010;
int n,m;
int tree[maxn][maxn];
void change(int x,int y,int z){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=n;j+=j&-j)
			tree[i][j]+=z;
}
int getsum(int x,int y){
	int ans=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ans += tree[i][j];
	return ans;
}
int main(){
	char ch;
	int a,b,c,d;
	scanf("%d %d",&n,&m);
	while(m--){
		cin >> ch;
		if(ch == 'C'){
			scanf("%d %d %d",&a,&b,&c);
			change(a,b,c);
		}
		else{
			scanf("%d %d %d",&a,&b,&c,&d);
			printf("%d\n",sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1));
		}
	}
	return 0;
}