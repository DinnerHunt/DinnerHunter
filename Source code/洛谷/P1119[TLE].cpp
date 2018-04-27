#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 205;
const int inf = 1e9;
int v,e,tim[maxd];
int dp[maxd][maxd];
struct node{
	int to,cost;
};
vector<node> edge[maxd];
void init(){
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
		{
			if(i==j) dp[i][j] = 0;
			else dp[i][j] = inf;
		}
}
void floyd(){
	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				if(dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j] = dp[i][k]+dp[k][j];
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int a,b,c,t;
	scanf("%d %d",&v,&e);
	init();
	for(int i=0;i<v;i++) scanf("%d",&tim[i]);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==b) continue;
		edge[a].push_back(node{b,c});
		edge[b].push_back(node{a,c});
	}
	scanf("%d",&t);
	int k=0,last=0;
	for(int i=0;i<t;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(tim[k]<=c){
			for(;tim[k]<=c;k++){
				for(int i=0;i<edge[k].size();i++)
					if(tim[edge[k][i].to]<=c)
					{
						dp[k][edge[k][i].to] = min(dp[k][edge[k][i].to],edge[k][i].cost);
						dp[edge[k][i].to][k] = min(edge[k][i].cost,dp[edge[k][i].to][k]);
					}
			}
			floyd();
		}
		if(dp[a][b]>=inf) printf("-1\n");
		else  printf("%d\n",dp[a][b]);
	}
	return 0;
}