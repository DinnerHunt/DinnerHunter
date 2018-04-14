#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 100005;
const int inf = -1e8;
struct node{
	int a,b,c;
	bool operator < (const node &b) const{
		return c<b.c;
	}
}arr[maxd];
int main(){
	int n,maxd=inf,now=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		sacnf("%d %d",&arr[i].a,&arr[i].b);
		arr[i].c = arr[i].a - arr[i].b;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		now += arr[i].a;
		ans = max(ans,now);
		now -= arr[i].c;
	}

	return 0;printf("%d",ans);
}