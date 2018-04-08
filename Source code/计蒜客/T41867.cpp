//jisuanke T41867 区间整数操作
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000000;
long long arr[maxn],loc[maxn];
int n,m;
void up(int p){
	arr[p] = arr[p<<1]+arr[p<<1|1];
}
void build(int pid,int l,int r){
	if(l==r){
		cin >> arr[pid];
		return ;
	}
	int mid = (l+r)/2;
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	up(pid);
}
void down(int p,int l,int r){
	if(loc[p]){
		int mid = (l+r)/2;
		arr[p<<1] += loc[p] * (mid-l+1);
		arr[p<<1|1] += loc[p] * (r-mid);
		loc[p<<1] = loc[p<<1|1] = loc[p];
		loc[p] = 0; 
	}
}
void modify(int pid,int l,int r,int x,int y,int c){
	if(x<=l&&r<=y){
		arr[pid] += (r-l+1)*c;
		loc[pid] = c;
		return ;
	}
	down(pid,l,r);
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y,c);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y,c);
	up(pid);
}
int query(int pid,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return arr[pid];
    down(pid,l,r);
    int mid =(l+r)/2,ans=0;
    if(x<=mid)
		ans +=query(pid<<1,l,mid,x,y);
	if(y>mid)
		ans+=query(pid<<1|1,mid+1,r,x,y);
    up(pid);
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
    cin >> n >> m;
    char ch;
    int a,b,c,flag=0;
    build(1,1,n);
    for(int i=0;i<m;i++){
        cin >> ch >> a >> b;
        if(ch == 'Q') {if(flag++)cout << endl;  cout << query(1,1,n,a,b);}
        else {
            cin >> c;
            modify(1,1,n,a,b,c);
        }
    }
	return 0;
}