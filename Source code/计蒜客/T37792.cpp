//jisuanke t37792 美好的邂逅
//DinnerHunt
#include <iostream>
using namespace std;
int n,m,dp[105][105],a,b,mx;
const int INF = 1000000;
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dp[i][j] = INF;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		if(a!=b) dp[a][b]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
				mx = max(mx,dp[i][j]);
			}
	if(mx<=6) cout << "Yes";
	else cout << "No";
	return 0;
}