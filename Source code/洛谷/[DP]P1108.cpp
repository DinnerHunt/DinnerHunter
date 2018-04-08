//P1108 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
int n,dp[5005],arr[5005],len=1;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	dp[1]=arr[n];
	for(int i=n-1;i>=1;i--){
		if(arr[i]>dp[len])
			dp[++len] = arr[i];
		else{
			int pos = lower_bound(dp+1,dp+len+1,arr[i]) - dp;
			dp[pos] = arr[i];
		}
		for(int i=1;i<=len;i++)
			cout << dp[i] <<" ";
		cout<< endl;
	}
	cout << len;
	return 0;
}