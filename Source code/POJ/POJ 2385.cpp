//POJ2385
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 1005;
int f[maxd][3];
int dp[maxd][35];
int main(){
	int a,b,d;
	scanf("%d %d",&a,&b);
	for(int i = 0;i<a;i++){
		scanf("%d",&d);
		f[i][d] = 1;
	}
	f[0][0] = f[0][1];
	for(int i = 0;i<a;i++)
		for(int j=0;j<=b;j++)
		{
			dp[i][j] = dp[i-1][j] + f[i][j%2+1];
			if(j) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+f[i][j%2+1]);
		}
	d= dp[a-1][0];
	for (int i=0;i<=b; ++i)
		d = max(dp[a-1][i],d);
	printf("%d",d);

	return 0;
}