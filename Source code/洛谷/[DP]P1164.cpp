//P1164 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int n,m,arr[105],ans,dp[10000];
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(j>arr[i])dp[j] = dp[j]+dp[j-arr[i]];
	cout << ans;
	return 0;
}