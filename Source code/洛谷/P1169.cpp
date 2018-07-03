#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 2005;
int n,m,ans1,ans2;
int dp[maxd][maxd],arr[maxd][maxd];
int l[maxd][maxd],h[maxd][maxd],r[maxd][maxd];
int L[maxd][maxd],R[maxd][maxd];
void solve(){
    memset(dp,0,sizeof(dp));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(l));
    memset(h,0,sizeof(l));
    memset(L,0,sizeof(l));
    memset(R,0,sizeof(l));
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=1;j<=m;j++)
			if(arr[i][j]) l[i][j] = t;
			else L[i][j] = 0,t=j;
		t = m+1;
		for(int j=m;j>0;j--)
			if(arr[i][j]) r[i][j] = t;
			else R[i][j] = m+1,t=j;
	}
	for(int i=1;i<=m;i++)	R[0][i] = m+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(arr[i][j])
		{
			dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) +1;
			h[i][j] = h[i-1][j]+1;
			L[i][j] = max(l[i][j]+1,L[i-1][j]);
			R[i][j] = min(r[i][j]-1,R[i-1][j]);
			ans1 = max(dp[i][j],ans1);
			ans2 = max((R[i][j]-L[i][j]+1)*h[i][j],ans2);
		}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
			if((i+j)%2) arr[i][j]^=1;
		}
	}
	solve();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			arr[i][j]^=1;
	solve();
	
	printf("%d\n%d",ans1*ans1,ans2);
	return 0;
}