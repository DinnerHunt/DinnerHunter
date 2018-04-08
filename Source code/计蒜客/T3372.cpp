//luogu P3372
//DinnerHunt;
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 300005; 
long long arr[maxn],col[maxn],n,m;
void up(int pid){
	arr[pid] = arr[pid<<1] + arr[pid<<1|1];
}
void down(int p,int l,int r){
	if(col[p]){
		int mid = (l+r)/2;
		arr[p<<1] += col[p]*(mid-l+1);
		arr[p<<1|1] += col[p]*(r-mid);
		col[p<<1] += col[p];
		col[p<<1|1] += col[p];
		col[p] = 0;
	}
}
void build(int pid,int l,int r){
	if(l==r)
	{
		cin >> arr[pid];
		return;
	}
	int mid = ( l + r )/2;
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	up(pid);
}
void xg(int pid,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y)
	{
		arr[pid] += (r-l+1)*v;
		col[pid] += v;
		return;
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	if(x<=mid) xg(pid<<1,l,mid,x,y,v);
	if(y>mid) xg(pid<<1|1,mid+1,r,x,y,v);
	up(pid);
}
long long query(int pid,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return arr[pid];
    down(pid,l,r);
    int mid = (l+r)/2;
    long long ans=0;
    if(x<=mid) ans+=query(pid<<1,l,mid,x,y);
    if(y>mid) ans+=query(pid<<1|1,mid+1,r,x,y);
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a,b,c,d;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin >> a >> b >> c;
		if(a==1){
			cin >> d;
			xg(1,1,n,b,c,d);
		}
		else 
			cout << query(1,1,n,b,c) << endl;
	}
	return 0;
}