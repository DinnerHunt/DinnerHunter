//P3373 luogu
//DinnerHunt
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const LL maxn = 1e6;
LL n,m,p;
LL arr[maxn*4],add[maxn],mul[maxn];
void up(LL pid){
	arr[pid] = (arr[pid<<1]+arr[pid<<1|1])%p;
}
void down(LL pid,LL l, LL r){
	if(mul[pid]!=1){
		arr[pid<<1] = (arr[pid<<1]*mul[pid])%p;
		arr[pid<<1|1] = (arr[pid<<1|1]*mul[pid])%p;
		add[pid<<1] = (add[pid<<1]*mul[pid])%p;
		add[pid<<1|1] = (add[pid<<1|1]*mul[pid])%p;
		mul[pid<<1] = (mul[pid<<1]*mul[pid])%p;
		mul[pid<<1|1] = (mul[pid<<1|1]*mul[pid])%p;
		mul[pid]=1;
	}
	if(add[pid]){
		LL mid = (l+r)>>1;
		add[pid<<1] = (add[pid<<1]+add[pid])%p;
		add[pid<<1|1] = (add[pid<<1|1]+add[pid])%p;
		arr[pid<<1] = (arr[pid<<1]+(mid-l+1)*add[pid])%p;
		arr[pid<<1|1] = (arr[pid<<1|1]+(r-mid)*add[pid])%p;
		add[pid]=0;
	}
}
void build(LL pid,LL l,LL r){
	if(l==r){
		scanf("%lld",&arr[pid]);
		return;
	}
	LL mid = (l+r)>>1;
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	up(pid);
}
void modify(LL pid,LL l,LL r,LL x,LL y,LL v,LL k){
	if(x<=l&&r<=y){
		if(k==1){
			arr[pid]=(arr[pid]+(r-l+1)*v%p)%p;
			add[pid]=(add[pid]+v)%p;
			return;
		}
		arr[pid] = (arr[pid]*v)%p;
		mul[pid] = (mul[pid]*v)%p;
		add[pid] = (add[pid]*v)%p;
		return;
	}
	down(pid,l,r);
	LL mid=(l+r)>>1;
	if(x<=mid) modify(pid<<1,l,mid,x,y,v,k);
	if(y>mid) modify(pid<<1|1,mid+1,r,x,y,v,k);
	up(pid);
}
LL query(LL pid,LL l,LL r,LL x,LL y){
	if(x<=l&&r<=y){
		return arr[pid];
    }
	down(pid,l,r);
	LL mid=(l+r)>>1,ans=0;
	if(x<=mid) ans= ans + query(pid<<1,l,mid,x,y)%p;
	if(y>mid) ans = ans + query(pid<<1|1,mid+1,r,x,y)%p;
	up(pid);
	return ans%p;
} 
int main(){
	scanf("%lld %lld %lld",&n,&m,&p);
	for(int i=0;i<=maxn;i++)
        mul[i] = 1;
	build(1,1,n);
	int a;
	LL b,c,d;
	for(LL i=0;i<m;i++){
		scanf("%d %lld %lld",&a,&b,&c);
		if(a==3){
			printf("%lld\n",query(1,1,n,b,c));
        }
		else{
			scanf("%lld",&d);
			modify(1,1,n,b,c,d,a);
		}
	}
	return 0;
}