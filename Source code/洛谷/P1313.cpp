#include <cstdio>
using namespace std;
const int mod = 10007;
int main(){
	int a,b,k,n,m;
	scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
	if(n+m!=k)printf("0");
	else
	{
		long long n = 1,r=1,d=1,ans;
		for(int i=k;i>=1;i--)
			k = k*i%mod;
		for(int i=m;i>=1;i--)
			r = r*i%mod;
		for(int i=n;i>=1;i--)
			d = d*i%mod;
		ans = (k/(r*d)%mod)*(a*b)%mod;
		printf("%lld",ans);
	}
	return 0;
}