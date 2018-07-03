#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 1005;
int arr[maxd][maxd],dp[maxd][maxd];
int main(){
	int n,m,a,b,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		arr[a][b] =1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!arr[i][j])
		dp[i][j] = max(max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
		ans = max(dp[i][j],ans);
	}
	printf("%d",ans);
	return 0;
}