//T37791 jisuanke 蒜头君的训练室
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 100000;
int	n,m,k;
int dp[305][305];
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dp[i][j] = 1;
			else dp[i][j] = INF;
		
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		cin >>a >>b >>c;
		dp[a][b]=c;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j] = min(dp[i][j],min(d[i][k],dp[k][j]));
	for(int i=1;i<=k;i++)
	{
		if(i!=1)cout << endl;
		cin >> a >> b;
		cout << dp[a][b];
	}
	return 0;
}