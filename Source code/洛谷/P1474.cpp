//P1474 货币系统
#include <cstdio>
using namespace std;
const int maxd = 10005;
int main()
{
	int n,m,v[30];
	long long dp[maxd];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	dp[0]=1;
	for(int i=0;i<n;i++)
		for(int j=v[i];j<=m;j++)
			dp[j] = dp[j] + dp[j-v[i]];
	printf("%lld",dp[m]);
	return 0;
}