//P1057 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int dp[100][100];
int x,y;
int main(){
	ios::sync_with_stdio(false);
	cin >> x >> y;
	dp[0][1]=1;
	for(int i=2;i<=x;i++)
		dp[0][i]=0;
	for(int i=1;i<=y;i++)
		for(int j=1;j<=x;j++)
		{
			if(j==1) dp[i][j] = dp[i-1][2]+dp[i-1][x];
			else if(j==x) dp[i][j] = dp[i-1][1]+dp[i-1][x-1];
			else dp[i][j] = dp[i-1][j+1]+dp[i-1][j-1];
		}
	cout << dp[y][1];
	return 0;
}