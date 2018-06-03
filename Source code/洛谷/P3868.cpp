#include <cstdio>
using namespace std;
typedef long long LL;
LL n,a[11],b[11];
LL exgcd(LL a,LL b ,LL &x,LL &y)
{
	if(!b){
		x=1;
		y=0;
		return a;
	}
	LL g = exgcd(b,a%b,x,y);
	LL t = x;
	x = y;
	y = t - a/b*y;
	return g;
}
LL qmul(LL a,LL b,LL mod)
{
	LL ans = 0;
	while(b>0)
	{
		if(b&1) ans = (ans+a)%mod;
		a = (a+a)%mod;
		b >>= 1;
	}
	return ans;
}
LL CRT()
{	
	LL M = 1;
	LL ans = 0;
	for(int i = 0;i<n;i++)
		M*= b[i];
	for(int i= 0;i<n;i++)
	{
		LL x,y;
		LL Mi = M/b[i];
		exgcd(Mi,b[i],x,y);
		x = (x%b[i] + b[i]) %b[i];
		ans = (ans + qmul (qmul(Mi,x,M),a[i],M) ) %M;
	}
	return (ans+M)%M;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%lld",&b[i]);
	for(int i=0;i<n;i++)
		a[i] = (a[i]%b[i]+b[i])%b[i];
	printf("%lld",CRT());
	return 0;
}