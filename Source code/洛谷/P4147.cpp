#include <cstdio>
#include <iostream>
using namespace std;
const int maxd = 1005;
int arr[maxd][maxd],h[maxd][maxd],l[maxd][maxd],r[maxd][maxd];
int L[maxd][maxd],R[maxd][maxd];
int main(){
	int n,m,ans=0;
	char ch;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin >> ch;
			if(ch == 'F')
				arr[i][j] = 1;
		}
	for(int i=1;i<=n;i++){
		int t = 0;
		for(int j =1;j<=m;j++)
			if(arr[i][j]) l[i][j] = t;
			else L[i][j] = 0,t=j;
		t = m+1;
		for(int j=m;j>=1;j--)
			if(arr[i][j]) r[i][j] = t;
			else R[i][j] = m+1,t=j;
	}
	for(int i=1;i<=m+1;i++) R[0][i] = m+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(arr[i][j]){
			h[i][j] = h[i-1][j]+1;
			L[i][j] = max(l[i][j]+1,L[i-1][j]);
			R[i][j] = min(r[i][j]-1,R[i-1][j]);
			ans = max((R[i][j] - L[i][j] + 1) * h[i][j],ans);
		}
	printf("%d",3*ans);
	return 0;
}