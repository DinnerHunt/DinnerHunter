#include <iostream>
#include <algorithm>
using namespace std;
int dp[10005],w[10005],k[10005],n,m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> w[i] >> k[i]; 
	for(int i=0;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--){
			dp[j] = max(dp[j],dp[j-w[i]]+k[i]);
		}
	}
	cout << dp[m];
	return 0;
}