//luogu P1028
//DinnerHunt
#include <iostream>
using namespace std;
int dp[1000];
int dfs(int a){
	int sum=1;
	for(int i=1;i<=a/2;i++){
		sum+=dfs(i);
	}
	return dp[a] = sum;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ans = dfs(n);
	cout << ans;
	return 0;
}