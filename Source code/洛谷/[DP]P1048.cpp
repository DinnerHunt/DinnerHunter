//P1048 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
int dp[105][1005],w[100],m[100];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> w[i] >> m[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(j<w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+m[i]);
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	return 0;
}