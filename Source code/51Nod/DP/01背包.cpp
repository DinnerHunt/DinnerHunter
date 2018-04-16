#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 10005;
int n,m,w[maxd],k[maxd],dp[maxd];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&w[i],&k[i]);
	for(int i=0;i<n;i++)
		for(int j=m;j>=w[i];j--)
			dp[j] = max(dp[j],dp[j-w[i]]+k[i]);
	printf("%d",dp[m]);
	return 0;
}