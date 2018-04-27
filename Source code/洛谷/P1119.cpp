#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 205;
const int inf = 1e9;
int v,e,tim[50010];
int dp[maxd][maxd];
void init(){
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
		{
			if(i==j) dp[i][j] = 0;
			else dp[i][j] = inf;
		}
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int a,b,c,t,k=0;
	scanf("%d %d",&v,&e);
	init();
	for(int i=0;i<v;i++) scanf("%d",&tim[i]);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==b) continue;
		dp[a][b] = c;
		dp[b][a] = c;
	}
	scanf("%d",&t);
	for(int s=0;s<t;s++){
		scanf("%d %d %d",&a,&b,&c);
			while(tim[k]<=c){
				for(int i=0;i<v;i++)
					for(int j=0;j<v;j++)
						dp[i][j] = min(dp[i][k]+dp[k][j],dp[i][j]);
                k++;
			}
		
		if(dp[a][b]>1e8||tim[a]>c||tim[b]>c) printf("-1\n");
		else printf("%d\n",dp[a][b]);
	}
	return 0;
}