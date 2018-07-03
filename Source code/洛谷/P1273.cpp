#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a,b,c;
const int maxd = 3005;
struct edge
{
	int to,next,v;
}e[maxd*maxd];
int f[maxd],eid,dp[maxd][maxd],val[maxd],arr[maxd];
void init(){
	eid = 0;
	memset(f,-1,sizeof(f));
}
void insert(int x,int y,int z){
	e[eid].to = y;
	e[eid].v = z;
	e[eid].next = f[x];
	f[x] = eid++;
}
int dfs(int x){
	if(x>n-m)
	{
		dp[x][1] = val[x];
		return 1;
	}
	int sum=0;
	for(int i=f[x];i+1;i=e[i].next)
	{
		int t = dfs(e[i].to);
		for(int j=0;j<=sum;j++) arr[j] = dp[x][j];
		for(int j=0;j<=sum;j++)
			for(int k=0;k<=t;k++)
				dp[x][j+k] = max(dp[x][j+k],arr[j]+dp[e[i].to][k]-e[i].v);
		sum+=t;
	}
	return sum;
}
int main(){
    init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-m;i++){
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{	
			scanf("%d %d",&b,&c);
			insert(i,b,c);
		}
	}
	memset(dp,~0x3f,sizeof(dp));
	for(int i=n-m+1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		dp[i][0] = 0;
	}
	dfs(1);
	for(int i=m;i>=1;i--)
		if(dp[1][i]>=0){
			printf("%d",i);
			break;
		}
	
	return 0;
}