#include <cstdio>
using namespace std;
typedef long long LL;
const int maxd = 100005;
LL now,last,c1[maxd],c2[maxd];
int n,m;
void add(LL* r,int k,int v){
	for(;k<=n;k+=(k&-k))
		r[k]+=v;
}
LL query(LL* r,int k){
	LL ans = 0;
	for(;k;k-=(k&-k))
		ans += r[k];
	return ans;
}
int main(){
	int a,b,c,d;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&now);
		add(c1,i,now-last);
		add(c2,i,(i-1)*(now-last));
		last = now;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d %d %d",&b,&c,&d);
			add(c1,b,d);
			add(c1,c+1,-d);
			add(c2,b,(b-1)*d);
			add(c2,c+1,-c*d);
		}
		else
		{
			scanf("%d %d",&c,&d);
			LL sum1 = (c-1)*query(c1,c-1) - query(c2,c-1);
			LL sum2 = d*query(c1,d) - query(c2,d);
			printf("%lld\n",sum2-sum1);
		}
	}
	return 0;
}