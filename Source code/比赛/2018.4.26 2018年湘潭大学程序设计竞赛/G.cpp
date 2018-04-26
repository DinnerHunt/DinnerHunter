#include <cstdio>
using namespace std;
typedef long long LL;
const int maxd = 1005;
const int inf = 1000000007;
LL ans[maxd],t;
int main()
{	
	scanf("%d",&t);
	ans[1]=1;
	ans[2]=1;
	for(int i=3;i<=1000;i++)
		ans[i] = (ans[i-1]+ans[i-2])mod inf;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a);
		printf("%d\n",(ans[a]+1+((a%inf)*(a%inf))%inf)%inf+(((a%inf)+(a%inf))%inf+(a%inf))%inf);
	}
	return 0;
}