//P1311 选择客栈
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxn = 200005;
int last[maxn],sum[maxn],col[maxn],now,ans;
int n,c,p,k;
int main(){
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&c,&k);
		if(k<=p) now = i;
		if(now >= last[c])
			sum[c] = col[c];
		last[c] = i;
		ans += sum[c];
		col[c]++;
	}
	printf("%d",ans);
	return 0;
}