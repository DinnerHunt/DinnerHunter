#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxd = 1505;
struct edge{
	int to,next;
}e[2*1505];
int f[maxd],eid,vis[maxd],dp[maxd][maxd];
void init(){
	memset(f,-1,sizeof(f));
	eid=0;
}
void insert(int a,int b){
	e[eid].to = b;
	e[eid].next = f[a];
	f[a] = eid++;
}
void dfs(int node){
	vis[node] = 1;
	dp[node][0]=0;
	dp[node][1]=1;
	for(int i=f[node];i+1;i = e[i].next)
	{
		if(vis[e[i].to]) continue;
		dfs(e[i].to);
		dp[node][0] += dp[e[i].to][1];
		dp[node][1] += min(dp[e[i].to][0],dp[e[i].to][1]);
	}
}
int main(){
	init();
	int a,b,c,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a,&b);
		for(int i=0;i<b;i++){
			scanf("%d",&c);
			insert(a,c);
			insert(c,a);
		}
	}
	dfs(0);
	printf("%d",min(dp[0][1],dp[0][0]));
	return 0;
}