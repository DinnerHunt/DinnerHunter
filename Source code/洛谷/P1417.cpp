#include <cstdio>
#include <algorithm>
using namespace std;
int const maxd = 100005;
struct node{
	int a,b,c;
	bool operator < (const &node other) const 
	{
		return b > other.b;	
	}
}arr[maxd];
int dp[maxd],ans=0;
int main(){
	int t,n;
	scanf("%d %d",&t,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i].a);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i].b);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i].c);
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++)
		for(int j=t;j>=1;j--)
			if(j>=c[i]) dp[j] = max(dp[j],dp[j-c[i]] +a[i]-j*b[i]);  
	for(int j=1;j<=t;j++) ans = max(ans,dp[j]);
	printf("%d",ans);		
	return 0;
}