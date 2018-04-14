#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxd = 10005;
LL arr[maxd];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	sort(arr,arr+n);
	int l = n,ans=0;
	for(int i=0;i<l;i++,l--)
	{
		if(arr[i]+arr[l-1]>=m)
			i--;
		ans++;
	}
    printf("%d",ans);
	return 0;
}