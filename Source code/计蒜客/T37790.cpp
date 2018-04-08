//T37790 jisuanke 蒜厂年会
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 100000;
int n,m,k,l,mx;
int d[305][305],arr[305];
void init(){
	for(int i=1;i<=n;i++){
		d[i][i] = 0;
	}
}
void dp(int e){
	for(int i=1;i<e;i++)
		for(int j=1;j<=e;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
					d[k][l] = min(d[k][l],d[k][i]+d[j][l]+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	fill(d+1,d+n+1,INF);
	init();
	for(int i=0;i<m;i++){
		cin >> k;
		for(int i=1;i<=k;i++)
			cin >> arr[i];
		dp(k);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			arr[i]+=dp[i][j];
		mx = max(arr[i],mx);
	}
	cout << mx;
	return 0;
}
