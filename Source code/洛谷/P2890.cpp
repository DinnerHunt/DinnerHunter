#include <iostream>
#include <algorithm>
using namespace std;
const int maxd = 2005;
const int len = 256;
int m,n;
int dp[maxd][maxd],del[len],add[len];
char str[maxd];
int main(){
	cin >> n >> m >> str+1;
	for(int i =0;i<n;i++)
	{
		cin >> str[0];
		cin >> add[str[0]] >> del[str[0]]; 
	}
	for(int l=2;l<=m;l++)
		for(int i=1;i+l-1<=m;i++)	
		{
			int j = i+l-1;
			if(str[i]==str[j]) dp[i][j] = dp[i+1][j-1];
			else dp[i][j] = min(dp[i+1][j]+min(add[str[i]],del[str[i]]),dp[i][j-1]+min(add[str[j]],del[str[j]]));
		}
	cout << dp[1][m];
	return 0;
}