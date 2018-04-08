//P1060 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
int DP[30][30005];
int main(){
	ios::sync_with_stdio(false);
	P arr[30];
	int n,m,a,b;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{	
		cin >> a >> b;
		arr[i] = P(a,b);
	}
	for(int i=1;i<=m;i++){
		a = arr[i].first;
		b = arr[i].second;
		for(int j=1;j<=n;j++)
		{	
			if(j>=a)dp[i][j] = max(dp[i-1][j-a]+a*b,dp[i-1][j]);
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout << dp[m][n];
	return 0;
}