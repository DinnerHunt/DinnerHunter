#include <cstdio>
using namespace std;
const int maxd = 10005;
typedef long long LL; 
LL n,a[maxd],m[maxd];
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL g =exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - a/b*y ; 
	return g;
}
LL CTR(){
	LL lcm = m[0],ans = a[0],x,y;
	for(int i=1;i<n;i++)
	{
		int aa = lcm, bb = m[i],cc = a[i] - ans;
		int gcd = exgcd(aa,bb,x,y);
		if(cc % gcd != 0 ) return -1;
		x = ((cc/gcd*x)%(bb/gcd) + (bb/gcd)) %  (bb / gcd);
		ans += x*lcm;
		lcm = lcm/gcd*bb;
		ans %= lcm;
	}
	return (ans%lcm+lcm)%lcm;
}
int main(){
	LL x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&m[i],&a[i]);
    }
 	printf("%lld",CTR());
    return 0;
}