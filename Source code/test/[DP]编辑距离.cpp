#include <iostream>
#include <algorithm>
using namespace std;
int dp[1005][1005];
string str1,str2;
int same(int i,int j){
	if(str1[i-1]==str2[j-1])
		return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> str1 >> str2;
	for(int i=str1.length();i>0;i--)
		dp[i][0] = i; 
	for(int i=str2.length();i>0;i--)
		dp[0][i] = i; 
	for(int i=1;i<=str1.length();i++)
		for(int j=1;j<=str2.length();j++){
			dp[i][j] = min(min(dp[i-1][j-1]+same(i,j),dp[i-1][j]+1),dp[i][j-1]+1);
		}
	cout << dp[str1.length()][str2.length()];
	return 0;
}