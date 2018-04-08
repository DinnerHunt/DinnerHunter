#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[205];
int a[205];
int k,x,y;
void dfs(int n,int m){
	if(n<1||n>k) return;
	if(dp[n] != -1&& dp[n]<=m) return;
    dp[n] = m;
	dfs(n+a[n],m+1);
	dfs(n-a[n],m+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> k >> x >> y;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=k;i++)
		cin >> a[i];
	dfs(x,0);
	cout << dp[y] ;
	return 0;
}