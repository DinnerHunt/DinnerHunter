#include <cstdio>
using namespace std;
const int maxd = 100005;
int tree[maxd*4],lazy[maxd*4],arr[maxd];
void up(int pid){
	tree[pid] = tree[pid<<1]+tree[pid<<1|1];
}
void down(int pid,int l,int r){
	if(lazy[pid])
	{
		int mid = (l+r)/2;
		tree[pid<<1] += lazy[pid]*(mid-l+1);
		tree[pid<<1|1] += lazy[pid]*(r-mid);
		lazy[pid<<1] += lazy[pid];
		lazy[pid<<1|1] += lazy[pid];
		lazy[pid] = 0;
	}
}
void modify(int pid,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		tree[pid] += (r-l+1)*k;
		lazy[pid] += k;
		return ;
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y,k);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y,k);
	up(pid);
}
int query(int pid,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return tree[pid];
	down(pid,l,r);
	int ans=0,mid=(l+r)/2;
	if(x<=mid)
		 ans += query(pid<<1,l,mid,x,y);
	if(y>mid) 
		 ans += query(pid<<1|1,mid+1,r,x,y);
	up(pid);
	return ans;
}
int main(){
	int m,n,a,b,c,d,e;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a==1){
			scanf("%d %d %d %d",&b,&c,&d,&e);
			modify(1,1,m,b,b,d);
			if(c>b) 
			modify(1,1,m,b+1,c,e);
			if(m!=c)
				modify(1,1,m,c+1,c+1,-(d+(c-b)*e));
		}
		else{
			scanf("%d",&b);
			printf("%d\n",query(1,1,m,1,b)+arr[b]);
		}
	}
	return 0;
}