//P1439 luogu
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	int n,cnt=0,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		c[a[i]] = i;
	for(int i=1;i<=n;i++)
		b[i] = c[b[i]];
	for(int i=1;i<=n;i++)
         if(d[k=lower_bound(d,d+cnt,b[i])-d]>=b[i]) d[k]=b[i];
         else d[cnt++]=b[i];
	printf("%d",cnt);
	return 0;
}
