#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 255;
const int inf = 1e9;
int dp_max[maxd][maxd],dp_min[maxd][maxd],arr[maxd],sum[maxd];
int ans_max,ans_min=inf,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=2*n;i++)
		sum[i] = arr[i%n+1]+sum[i-1];
	for(int i=n*2-1;i>0;i--)
		for(int j=i+1;j-i<n;j++){
            dp_min[i][j] = inf;
			for(int k=i;k<j;k++){
				dp_max[i][j] = max(dp_max[i][j],dp_max[i][k]+dp_max[k+1][j]+sum[j]-sum[i-1]);
				dp_min[i][j] = min(dp_min[i][j],dp_min[i][k]+dp_min[k+1][j]+sum[j]-sum[i-1]);
			}
		}
    for(int i=1;i<=n;i++)
    {
    	ans_min = min(ans_min,dp_min[i][i+n-1]);
    	ans_max = max(ans_max,dp_max[i][i+n-1]);
    }
	printf("%d\n%d",ans_min,ans_max);
	return 0;
}