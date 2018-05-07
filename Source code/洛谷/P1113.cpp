#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 10005;
int n,d[maxd],ans;
int main(){
	int a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		d[a] = b;
		while(scanf("%d",&c)!=EOF&&c)
			d[i] = max(d[c]+b,d[i]);
		ans = max(d[i],ans);
	}
	printf("%d",ans);
	return 0;
}

