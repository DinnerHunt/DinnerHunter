//P2983
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxd = 100500;
struct node{
	LL x,y;
	bool operator < (const node &other) const {
		return y<other.y;
	}
}arr[]
int main(){
	LL n,b,ans=0;
	scanf("%lld %lld",&n,&b);
	for(int i=0;i<n;i++)
		scanf("%lld %lld",&arr[i].x,&arr[i].y);
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(b>=arr[i].x*arr[i].y)
		{
			b -= arr[i].x*arr[i].y;
			ans+=arr[i].x;
		}
		else
		{
			ans+=b/arr[i].y;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}