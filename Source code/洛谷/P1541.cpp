#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 45;
int dp[maxd][maxd][maxd][maxd];
int size[5],arr[355];
int main()
{
	int n,m,x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		size[x]++;
	}
	for(int a=0;a<size[1];a++)
		for(int b=0;b<size[2];b++)
			for(int c=0;c<size[3];c++)
				for(int d=0;d<size[4];d++)
				{
					int p = 1+a+b*2+c*3+d*4;
					if(!a) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a-1][b][c][d]+arr[p]);
					if(!b) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b-1][c][d]+arr[p]);
					if(!c) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c-1][d]+arr[p]);
					if(!d) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c][d-1]+arr[p]);
				}
	printf("%d",dp[size[1]][size[2]][size[3]][size[4]]);
	
	return 0;

}