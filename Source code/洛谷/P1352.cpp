#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 6005;
int fa[maxd],dp[maxd][2],val[maxd];
bool vis[maxd];
struct node{
	int to,next;
}e[2*maxd];
int f[maxd],eid;
void init(){
	eid=0;
	memset(f,-1,sizeof(f));
}
void insert(int x,int y){
	e[eid].to =  y;
	e[eid].next = f[x];	
	f[x] = eid++;
}
void tree_dp(int node){
	vis[node] = 1;
	dp[node][0] = 0;
	dp[node][1] = val[node];
	for(int i=f[node];i+1;i=e[i].next)
	{
		if(vis[e[i].to]) continue;
		tree_dp(e[i].to);
		dp[node][1] += dp[i][0];
		dp[node][0] += max(dp[i][1],dp[i][0]);
	}
}
int main(){
	int a,b,n,root=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		insert(b,a);
		fa[a] = b;
	}
	while(fa[root]) root = fa[root];
	tree_dp(root);
	printf("%d\n",max(dp[root][0],dp[root][1]));
	return 0;
}