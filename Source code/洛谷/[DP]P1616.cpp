//P1616 luogu
//DinnerHunt


#include <iostream>
#include <algorithm>
using namespace std;
int dp[10000][100000];
int n,m,w[10000],k[10000];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> w[i] >> k[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j>w[i]) dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+w[i]*k[i]);
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout << dp[m][n];
	return 0;
}