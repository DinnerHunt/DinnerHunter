#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd  = 40005;
typedef long long LL;
LL tree[maxd*4];
int n;
void down(int pid){
	tree[pid<<1] = max(tree[pid],tree[pid<<1]);
	tree[pid<<1|1] = max(tree[pid],tree[pid<<1|1]);
	
}
void modify(int pid,int l,int r,int x,int y,LL k)
{
	down(pid);
	if(x<=l&&r<=y){
		tree[pid] =max(tree[pid],k);
		return ;
	}
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y,k);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y,k);
}
LL query(int pid,int l,int r){
	down(pid);
	if(l==r)
		return tree[pid];
	int mid = (l+r)/2;
	LL ans;
	ans += modify(pid<<1,l,mid);
	ans += modify(pid<<1|1,mid+1,r);
	return ans;
}
int main(){
	int a,b;
	LL c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %lld",&a,&b,&c);
		modify(1,1,maxd,a,b,c);
	}
	printf("%lld",query(1,1,maxd));
	return 0;
}