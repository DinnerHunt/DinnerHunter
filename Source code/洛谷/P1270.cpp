#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 205;
struct node{
	int to,next,v;
}e[maxd*maxd];
int f[maxd],eid,time,num,val[maxd*maxd],arr[maxd],sum;
// dp[i][j] 第i个点，获取j副画最少需要多少时间
int dp[maxd*maxd][maxd];
void init(){

	memset(dp,1,sizeof(dp));
	memset(f,-1,sizeof(f));
	eid=0;
}
void insert(int a,int b,int c){
	e[eid].to = b;
	e[eid].next = f[a];
	e[eid].v = c; 
	f[a] = eid++;
}
void read(int x){
	int a,b,k=++num;
	scanf("%d %d",&a,&b);
	insert(x,k,a);
	if(!b) {
		read(k);
		read(k);
	}
	else {val[num] = b,sum+=b};
}
int dfs(int x){
	if(val[x]){
		for(int i=1;i<=val[x];i++)
			dp[x][i] = dp[x][i-1]+5;
		return val[x];
	}
	int sum = 0;
	for(int i=f[x];i+1;i = e[i].next)
	{
		int t = dfs(e[i].to);
		for(int j=0;j<=sum;j++) arr[j] = dp[x][j];
		for(int j=0;j<=sum;j++)
			for(int k=1;k<=t;k++)	
			dp[x][k+j] = min(dp[x][k+j],dp[x][j]+dp[e[i].to][k]+e[i].v);
	}
}
int main(){
	init();
	scanf("%d",&time);
	read(0);
	dfs(0);
	for(int i=sum;i>=0;i--)
		if(dp[0][i]<=time){
			printf("%d",i);
			break;
		}
	return 0;
}