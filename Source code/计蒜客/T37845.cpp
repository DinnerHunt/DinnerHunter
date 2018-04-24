#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> s;
string str;
int dp[1<<18];
bool grep(int x,int y){
	return x|y == y;
}
bool check(int x){
	string st = "";
	int len=0;
	for(int i=0;(1<<i)<=x;i++)
		if(x&(1<<i)){
			st+=s[i];
			len++;
		}
	for(int i = 0; i <=len/2; i++)
		if(st[i]!=st[len-1-i])
			return false;
	return true;
}
int main(){
	cin >> str;
	int len = strlen(str);
	for(int i=1;i<len;i++)
		if(check(i))
			s.push_back(i);
	memset(dp,1,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<len;i++)
		for(int j=0;j<=s.size();i++)
			if(s[j]<=i&&grep(i,s[j]))
				dp[i] = min(dp[i],dp[i^j]+1);
	printf(dp[len-1]);
	return 0;
}