#include <cstdio>
using namespace std;
const int maxd = 100005;
typedef long long LL;
struct node{
	LL num,add,mul;
}arr[maxd*4];
int n,mod,m;
void up(int pid){
	arr[pid].num = (arr[pid<<1].num + arr[pid<<1|1].num)%mod;
}
void down(int pid,int l,int r){
	if(arr[pid].mul>0||arr[pid].add>0)
	{
		int mid = (l+r)/2; 
		arr[pid<<1].num = ( arr[pid<<1].num*arr[pid].mul+arr[pid].add*(mid-l+1))%mod;
		arr[pid<<1|1].num = (arr[pid<<1|1].num*arr[pid].mul+arr[pid].add*(r-mid) )%mod;
		arr[pid<<1].mul = (arr[pid<<1].mul * arr[pid].mul)%mod;
		arr[pid<<1|1].mul = (arr[pid<<1|1].mul * arr[pid].mul)%mod;
		arr[pid<<1].add = (arr[pid<<1].add*arr[pid].mul+arr[pid].add) %mod;
		arr[pid<<1|1].add = (arr[pid<<1|1].add*arr[pid].mul+arr[pid].add)%mod;
		arr[pid].add = 0;
		arr[pid].mul = 1;
	}	
}
void build(int pid,int l,int r){
	arr[pid].mul = 1; 
	if(l == r)
	{
		scanf("%lld",&arr[pid].num);
		printf("%lld",arr[pid].num);
		return;
	}
	int mid = (l+r)/2;
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	up(pid);
}
void modify(int pid,int l,int r,int x,int y,LL z,int k){
	if(x<=l&&r<=y)
	{
		if(k==1)
		{
			arr[pid].num = (arr[pid].num*z)%mod;
			arr[pid].mul = (arr[pid].mul*z)%mod;
			arr[pid].add = (arr[pid].add*z)%mod;
			return;
		}
		else
		{
			arr[pid].num = (arr[pid].num+z*(r-l+1))%mod;
			arr[pid].add = (arr[pid].add+z)%mod;
			return;
		}
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y,z,k);
	if(mid < y)
		modify(pid<<1|1,mid+1,r,x,y,z,k);
	up(pid);
}
LL query(int pid,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return arr[pid].num;
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	int ans=0;
	if(x<=mid)
		ans += query(pid<<1,l,mid,x,y)%mod;
	if(y>mid) 
		ans += query(pid<<1|1,mid+1,r,x,y)%mod;
	up(pid);
	return ans;
}

int main(){
    int a,b,c,d;
	scanf("%d %d",&n,&mod);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
	    scanf("%d",&a);
	    if(a==3)
	    {
	        scanf("%d %d",&b,&c);
	        printf("%lld\n",query(1,1,m,b,c));
	    }
        else
        {
            scanf("%d %d %lld",&b,&c,&d);
            modify(1,1,m,b,c,d,a);
        }
	}
	return 0;
}