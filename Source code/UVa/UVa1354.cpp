//UVa1354 Mobile Computing
//DinnerHunt
#include <cstdio>
using namespace std;
struct node{
	double l,r,w;
	node operator + (const node b){
		node c;
		c.w = w+b.w;
		c.l = max(l+w/c.w,r-b.w/c.w);
		c.r = max(b.r+w/c.w,a.r+c.w/c.w);
		return b;
	}
}a[10];
double width,ans;
int n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf %d",&width,&n);
		for(int i=0;i<n;i++){
			scanf("%lf",&a[i].w);
			a[i].l=0;
			a[i].r=0;
		}
		ans = -1;
		dfs(0);
		printf("%lf\n",ans);
	}
	return 0;
}