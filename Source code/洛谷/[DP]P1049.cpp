//luogu P1049
//DinnerHunt
#include <iostream>
using namespace std;
int n,dp[35][20005],arr[35],m;
int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> arr[i];
	for(int i=0;i<=n;i++)
		dp[0][i] = i;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{   
            if(j>=arr[i]) dp[i][j] = max(dp[i][j-1],dp[i][j-arr[i]]+arr[i]);
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	cout << dp[m][n]-n;
	return 0;
}