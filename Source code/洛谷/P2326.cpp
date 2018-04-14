//luogu P2326
//DinnerHunt
#include <cstdio>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxd = 100005;
long long arr[maxd],ans,n,m,flag;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{	
		ans =0;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
			scanf("%d",&arr[j]);
		sort(arr,arr+m);
		for(int j=0;j<m-1;j++)
		{
			ans = max(ans,arr[j]&arr[j+1]);
			ans = max(ans,arr[j]&arr[j+2]);
		}
		printf("Case #%lld: %lld\n",++flag,ans);
	}
	return 0;
}