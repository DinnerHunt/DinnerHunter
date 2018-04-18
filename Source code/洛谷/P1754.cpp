#include <cstdio>
using namespace std;
int n;
long long dp[100][100];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
	printf("%lld",dp[n][n]);
	return 0;
}