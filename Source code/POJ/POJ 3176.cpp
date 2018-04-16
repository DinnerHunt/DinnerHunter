//POJ 3176
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 355;
int dp[maxd],arr[maxd],ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++)
			scanf("%d",&arr[j]);
		for(int j=i-1;j>=0;j--){
			if(!i) dp[j] = dp[j]+arr[j];
			else dp[j] = arr[j]+max(dp[j-1],dp[j]);
			ans = max(dp[j],ans);
		}
	}
	printf("%d",ans);
	return 0;
}