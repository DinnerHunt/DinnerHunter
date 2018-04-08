//P1434 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
int arr[105][105];
int dp[105][105];
int n,m,mx=0;
int dps(int x,int y)
{
	if(dp[x][y]) return dp[x][y];
	int ans=0,k=arr[x][y];
	if(x+1>0)if(arr[x+1][y]>k) ans=max(ans,dps(x+1,y));
	if(x-1>0)if(arr[x-1][y]>k) ans=max(ans,dps(x-1,y));
	if(y+1>0)if(arr[x][y+1]>k) ans=max(ans,dps(x,y+1));
	if(y-1>0)if(arr[x][y-1]>k) ans=max(ans,dps(x,y-1));
    dp[x][y] = ans+1;
    
	return dp[x][y]; 
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> arr[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(dp[i][j]==0) dp[i][j] = dps(i,j);
			mx=max(mx,dp[i][j]);
		}
	cout << mx;
	return 0;
}