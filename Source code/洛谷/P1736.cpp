#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxd = 2505;
int arr[maxd][maxd],dp[maxd][maxd],a1[maxd][maxd],a2[maxd][maxd];
int main(){
	int m,n,ans=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[i][j]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{
			if(!arr[i][j])
			{
				a1[i][j] = a1[i][j-1]+1;
				a2[i][j] = a2[i-1][j]+1;
			}
			else
				dp[i][j] = min(dp[i-1][j-1],min(a1[i][j-1],a2[i-1][j]))+1;
			ans = max(ans,dp[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	for(int i=1;i<=m;i++)
		for(int j=n;j>=1;j--)
		{
			if(!arr[i][j])
			{
				a1[i][j] = a1[i][j+1]+1;
				a2[i][j] = a2[i-1][j]+1;
			}
			else dp[i][j] = min(dp[i-1][j+1],min(a1[i][j+1],a2[i-1][j]))+1;
			ans = max(dp[i][j],ans);
		}
	printf("%d",ans);
	return 0;
}