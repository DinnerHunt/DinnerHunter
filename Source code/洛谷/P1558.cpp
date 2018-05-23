//P1558
#include <cstdio>
#include <iostream>
using namespace std;
const int maxd = 100005;
const int inf = 1<<31;
int tree[maxd*4],arr[maxd*4];
void up(int pid){
	tree[pid] = tree[pid<<1] | tree[pid<<1|1];
}
void build(int pid,int l,int r){
	tree[pid] = inf;
	if(l==r){
		return;
	}
	int mid = (l+r)/2;
	build(l,mid);
	build(mid+1,r);
}
void down(int pid){
	tree[pid<<1] = arr[pid];
	tree[pid<<1|1] = arr[pid];
	arr[pid<<1] = arr[pid];
	arr[pid<<1|1] = arr[pid];
	arr[pid] = 0;
}
void modify(int pid,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		tree[pid] = z;
		arr[pid] = z;
		return;
	}
	down(pid);
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y,z);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y,z);
	up(pid);
}
int query(int pid,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return tree[pid];
	down(pid);
	int mid=(l+r)/2,ans=0;
	if(x<=mid)
		ans|= query(pid<<1,l,mid,x,y);
	if(y>mid)
		ans|= query(pid<<1|1,mid+1,r,x,y);
	up(pid);
	return ans;
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=x&1;
		x= x>> 1;
	}
	return ans;
}
int main(){
	char ch;
	int a,b,c,n,m;
	scanf("%d %d %d",&n,&m,&m);
	for(int i=0;i<m;i++)
	{
		cin >> ch;
		if(ch == 'C')
		{
			scanf("%d %d %d",&a,&b,&c);
			modify(1,1,n,a,b,1<<c);
		}
		else
		{
			scanf("%d %d",&a,&b);
			//printf("%d\n",sum(query(1,1,n,a,b)));
		}
	}
	printf("%d %d",arr[2],arr[3]);
	return 0;
}