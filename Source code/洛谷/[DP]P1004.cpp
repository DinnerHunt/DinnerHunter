//P1004 luogu
//DinnerHunt 
#include <iostream>
using namespace std;
int dp[55][55][55][55],arr[55][55],n,a,b,c;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	while(cin >> a >> b >> c){
		if(!a&&!b&&!c)
			break;
		arr[a][b]=c;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
				{
					f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i][j-1][k-1][l],max(f[i-1][j][k][l-1],f[i][j-1][k][l-1])))+a[i][j]+a[k][l];
					if(i==k&&j==l) f[i][j][k][l] -= a[i][j];
				}
	cout << f[n][n][n][n];
	return 0;
}