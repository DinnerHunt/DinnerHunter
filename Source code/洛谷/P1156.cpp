#include <cstdio>
#include <cstring>
#include <algorith>
using namespace std;
int dp[105];
struct node{
	int t,f,h;
	bool operator < (const node &other) const
	{
		return t <other.t;
	}
}arr[105];
int main(){
	int d,n;
	scanf("%d %d",&d,&n);
	for(int i=0;i<n;i+)
		scanf("%d %d %d",&arr[i].t,&arr[i].f,&arrarr[i].h);
	sort(arr,arr+n);
	memset(dp,-1,sizeof(dp));
	dp[0] = 10; 
	for(int i=0;i<n;i++)
		for(int j=d;i>=0;i--)
		{
			if(dp[j] >= arr[i].t)
			{
				if(j+arr[i].h>=d)
				{
					printf("%d",arr[i].t);
					return 0;
				} 
				dp[j+arr[i].h] = max(dp[j+arr[i].h],dp[j]); 
				dp[j] = max(dp[j],dp[j]+arr[i].f);
			}
		}
	printf("%d",dp[0]);
	return 0;
}
