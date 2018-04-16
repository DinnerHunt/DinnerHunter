//luogu P2066
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxd = 20;
int dp[maxd];
int main(){
	int x,y,z;
	scanf("%d %d",&x,&y);
	for(int i=0;i<n;i++)
		for(int j=y-1;j>=0;j--){
			sacnf("%d",&z);
			dp[j] = max(dp[j],dp[y-1-j]+z);
		}
	printf("%d")
	return 0;
}
