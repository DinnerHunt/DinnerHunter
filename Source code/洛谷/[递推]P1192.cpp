//P1192 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int n,m,yh[100005];
const int MX = 100003;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	yh[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i&&j<=k;j++)
		{
			yh[i] += yh[i-j];
			yh[i] %= MX;
		}
	cout << yh[n];
	return 0;
}