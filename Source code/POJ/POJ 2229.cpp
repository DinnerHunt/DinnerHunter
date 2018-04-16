//POJ 2229
#include <cstdio>
using namespace std;
const int maxd = 1000000000;
int dp[1000001];
int main(){
	int n;
	scanf("%d",&n);
	dp[1]=1;
	for(int i=2;i<=n;i++)
		if(i&1)
			dp[i] = dp[i-1];
		else
			dp[i] = (dp[i-1]+dp[i>>1])%maxd;
	printf("%d",dp[n]);
	return 0;
}