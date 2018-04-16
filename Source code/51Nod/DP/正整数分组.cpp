#include <iostream>
#include <algorithm>
using namespace std;
int dp[10005],a[10005],n,m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		m+=a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=m/2;j>=a[i];j--){
			dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout << abs(m-dp[m/2]-dp[m/2]);
	return 0;
}