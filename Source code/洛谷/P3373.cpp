#include <cstdio>
using namespace std;
const int maxd = 100000;
int arr,[maxd*4],loc[maxd*4],loc_1[maxd*4];
int n,m,mod;
void up(int pid){
	arr[pid] = arr[pid<<1] +arr[pid<<1|1];
}
void build(int pid,int l,int r){
	if(l==r){
		scanf("%d",&arr[pid]);
		arr[pid]%=mod;
		return;
	}
	int mid = (l+r);
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	up(pid);
}
void down(int pid,int l,int r){
	if(loc_1[pid])
	{
		arr[pid<<1] *= loc_1[pid];
		arr[pia<<1|1] *= loc_1[pid];
		arr[pid<<1] %=mod;
		arr[pid<<1|1] %=mod;
		loc[pid<<1] *= loc_1[pid];
		loc[pid<<1|1] *= loc_1[pid]; 
		loc_1[pid<<1] *=loc_1[pid];
		loc_1[pid<<1|1] *= loc_1[pid];
		loc_1[pid]=0;
	}
	if(loc[pid])
	{
		int mid = (l+r)/2;
		arr[pid<<1] += loc[pid]*(mid-l-1);
		arr[pid<<1|1] += loc[pid]*(r-mid);
		arr[pid<<1] %=mod;
		arr[pid<<1|1] %=mod;
		loc[pid<<1] += loc[pid];
		loc[pid<<1|1] += loc[pid];
		loc[pid<<1] %= mod;
		loc[pid<<1|1] %= mod;
		loc[pid]=0;
	}
}
void modify(int pid,int l,int r,int x,int y,int z,int h)
{
	if(x<=l&&r<=y)
	{
		if(h==2){
			arr[pid] += ((r-l+1)*z%mod);
			arr[pid]%=mod;
			loc[pid] += z;
			loc[pid]%=mod;
		}
		else
		{
			arr[pid] *= z;
			arr[pid]%=mod;
			loc_1[pid] *= z;
		}
		return;
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	if(x <= mid)
		modify(pid<<1,l,mid,x,y,z,h);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y,z,h);
	up(pid);
}
int query(int pid,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return arr[pid];
	down(pid);
	int ans=0,mid=(l+r)/2;
	if(x<=mid)
		ans+=query(pid<<1,l,mid,x,y);
	if(y>mid)
		ans+=query(pid<<1|1,mid+1,t,x,y);
	up(pid);
	return ans%mod;
}
int main(){
	int a,b,c,d;
	scanf("%d %d",&n,&m,&mod);
	build(1,1,m);
	for(int i=0;i<m;i+=)
	{
		scanf("%d",a);
		if(a!=3){
			scanf("%d %d %d",&b,&c,&d);
			modify(1,1,m,b,c,d,a);
		}
		else
		{
			scanf("%d %d",&b,&c);
			printf("%d\n",query(1,1,m,b,c));
		}
	}
	return 0;
}