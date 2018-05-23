#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 100005;
int n,m,arr[maxd],diff[maxd],ans,dj[maxd],sj[maxd],tj[maxd];
bool ok(int k){
	memset(diff,0,sizeof(diff));
	int ans = 0;
	for(int i=1;i<=k;i++){
		diff[sj[i]]+=dj[i];
		diff[tj[i]+1] -= dj[i];
	}
	for(int i=1;i<=n;i++){
		ans += diff[i];
		if(ans>arr[i])
			return false;
	}
}
int main(){
	int a,b,c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&dj[i],&sj[i],&tj[i]);
	int l = 1,r = n;
	while(l<r){
		int mid = l+(r-l)/2;
		if(ok(mid)) l = mid+1;
		else r = mid;
	}
	if(l==n)
		printf("0");
	else 
		printf("-1\n%d",l);
	return 0; 
}