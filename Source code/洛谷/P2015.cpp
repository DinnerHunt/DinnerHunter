#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 105;
struct edge
{
	int to,next,v;
}e[maxd*maxd];
int f[maxd],eid;
void init(){
	memset(f,-1,sizeof(f));
	eid=0;
}
void insert(int a,int b,int c){
	e[eid].to = b;
	e[eid].v = c;
	e[eid].next = f[a];
	f[a] = eid++;
}
//dp[i][j] 第n个节点，保留k根树枝，最大能保存多少个苹果
int n,m,val[maxd],dp[maxd][maxd],vis[maxd],arr[maxd];
int dfs(int x){
	if(f[x] == -1) return 0;
	vis[x] =1;
	int sum = 0;
	for(int i = f[x];i+1;i=e[i].next)
	{   if(vis[e[i].to]) continue;
		int t = dfs(e[i].to)+1;
		for(int j=0;j<=sum;j++) arr[j] = dp[x][j];
		for(int j=0;j<=sum;j++)
			for(int k=1;k<=t&&j+k<=m;k++)
				dp[x][j+k] = max(dp[x][j+k],arr[j]+dp[e[i].to][k-1]+e[i].v);
			
		sum+=t;
	}
	return sum;
}
int main()
{	
    init();
	int a,b,c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		insert(a,b,c);
		insert(b,a,c);
	}
	dfs(1);
	printf("%d",dp[1][m]);
	return 0;
}