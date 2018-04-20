#include <cstdio>
#include <algorithm>
using namespace std;
int dp[20],va[20][20];
int main(){
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&va[i][j]);
	for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--)
            for(int k=1;k<=m;k++)
            {
                if(j<k) continue;
                dp[j] = max(dp[j-k]+va[i][k],dp[j]);
            }
    }
	printf("%d",dp[m]);
	return 0;
}