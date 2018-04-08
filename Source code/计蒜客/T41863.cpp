//jisuanke T41863 最甜的苹果
//DinnerHunt
#include<iostream>
using namespace std;
const int maxn = 262144 * 2;
int tree[maxn];
void build(int pid,int l,int r){
	if(l==r){
		cin >> tree[pid];
		return;
	}
	int mid = (l+r)/2;
	build(pid<<1,l,mid);
	build(pid<<1|1,mid+1,r);
	tree[pid] = tree[pid<<1]+tree[pid<<1|1];
}
void modify(int pid,int l,int r,int x,int v){
	if(l == r)
	{
		tree[pid] = v;
		return;
	}
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,v);
	else
		modify(pid<<1|1,mid+1,r,x,v);
	tree[pid] = tree[pid<<1]+tree[pid<<1|1];
}
int query(int pid,int l,int r,int x,int y){
	if(x<=l == r <= y)
		return tree[pid];
	int mid = (l+r)/2,ans=0;
	if(x<=mid) ans+=query(pid<<1,l,mid,x,y);
	if(y>mid) ans+=query(pid<<1|1,mid+1,r,x,y);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	char ch;
	int a,b,flag;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin >> ch >> a >> b;
		if(ch == 'Q'){
			if(flag++) cout << endl;
			cout << query(1,1,n,a,b);
		}
		if(ch == 'U'){
			modify(1,1,n,a,b);
		}
	}
	return 0;
}