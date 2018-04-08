#include <bits/stdc++.h>
using namespace std

int d[1010][1010] = {0};

int main(){
	string A,B;
	cin >> A>> B;
	int m=A.size();
	int n=B.size();
	for(int i=1;i<=m;++i){
		for(int j=1;j<n;++j){
			if(A[i-1]==B[j-1])
				d[i][j]=d[i-1][j-1]+1;
			else d[i][j] = max(d[i][j-1],d[i-1][j]);
		}
	}
	int len=d[m][n];
	string ans;
	int i=m,j=n;
	while(d[i][j]){
		if(d[i][j]==d[i-1][j]) --i;
		else if(d[i][j] == d[i][j-1]) --j;
		else ans.push_back(A[i-1]), --i,--j;
	}
	for(int i=len-1;i>=0;--i)
		cout << ans[i];
	return 0;
}