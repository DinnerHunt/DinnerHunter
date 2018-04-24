#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 5005;
int dp[maxd],a[maxd],s[105];
int right,a,b,c,cnt,ans = 1e9;
int main(){
	scanf("%d",&right);
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=c;i++)
		scanf("%d",&s[i]);
	s[c+1] = right;
	sort(s,s+c+2);
	for(int i=1;i<=c+1;i++)
	{
		if(s[i]-s[i-1]>b)
			cnt += (s[i]-s[i-1])%t+t;
		else 
			cnt += s[i]-s[i-1];
		if(i!=c+1) a[cnt] = 1;
	}
	memset(dp,1,sizeof(dp));
	dp[0]=0;
	for(int i=a;i<=cnt+t;i++)
		for(int j=a;j<=b;j++)
			dp[i] = min(dp[i],dp[i-j]+a[i]);
	for(int i=cnt;i<=cnt+t;i++)
		ans = min(dp[i],ans);
	printf("%d",ans);
	return 0;
}