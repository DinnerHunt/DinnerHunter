#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 300010;
int dp[maxd];
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	for(int i=1;i<=z;i++)
		if(x>=10){ dp[i]=dp[i-1]+60;x-=10;}
		else{dp[i]=dp[i-1];x+=4;}
	for(int i=1;i<=z;i++)
	{
		dp[i] = max(dp[i],dp[i-1]+17);
		if(dp[i]>=y)
		{
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",dp[z]);
	return 0;
}