#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 1005;
const int maxn = 12005;
int n,dp[maxd][maxn],a[maxd],b[maxd];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]);
	memset(dp,0x7f,sizeof(dp));
	dp[0][5000] = 0;
	for(int i=1;i<=n;i++)
		for(int j = -5000;j<=5000;j++)
		{
			int dis = a[i]-b[i];
			dp[i][j+5000] = min(dp[i-1][j-dis+5000],dp[i-1][j+dis+5000]+1);
		}
	for(int i=0;i<=5000;i++)
	{
		int ans = min(dp[n][i+5000],dp[n][-i+5000]);
		if(ans<=1000)
		{
			printf("%d\n",ans);
		}
		break;
	}
	return 0;
}