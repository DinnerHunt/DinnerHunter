//POJ 2393
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 10005;
int price[maxd],number[maxd];
int main(){
	int n,m;
	long long ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&price[i],&number[i]);
	for(int i=0;i<n;i++)
	{
		ans += price[i] * number[i];
		for(int j=1;i+j<n;j++)
			price[i+j] = min(price[i+j],price[i]+j*m);
	}

	printf("%lld\n",ans);
	return 0;
}