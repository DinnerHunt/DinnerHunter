#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 105;;
int dp[maxd][maxd][maxd],G[maxd][maxd];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&G[i][j]);
	for(int i=2;i<=n+m-1;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				if(i-j<0||i-k<0) continue;
				dp[i][j][k] = max(
					max(dp[i-1][j-1][k],dp[i-1][j][k-1]),
					max(dp[i-1][j-1][k-1],dp[i-1][j][k])
				) + G[j][i-j+1]+G[k][i-k+1];
				if(j==k) dp[i][j][k] -= G[j][i-j+1];
			}
	printf("%d",dp[n+m-1][n][n]);
	return 0;
}