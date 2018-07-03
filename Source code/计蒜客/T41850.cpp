#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 100010;
int dp[maxd];
int n,m,w[105],s[105],ans;
int main(){
	scanf("%d %d",&n,&m);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)
		{
			if(!j)dp[j] = s[i];
			else if(dp[j]!=-1) dp[j] = s[i];
			else if(j>=w[i]&&dp[j-w[i]]>0) dp[j] = dp[j-w[i]]-1;
		}
    }
	for(int i=1;i<=m;i++)
		if(dp[i]!=-1)
			ans++;
	printf("%d",ans);
	return 0;
}