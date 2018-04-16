#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL mad,ans,n,a;
int main()
{	
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a);
		mad = max(mad+a,a);
		ans = max(mad,ans);
	}
	printf("%lld",ans);
	return 0;
}