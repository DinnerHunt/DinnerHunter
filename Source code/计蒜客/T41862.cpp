//jisuanke t41862 斑点蛇
//DinnerHunt
#include <iostream>
using namespace std;
const int maxn = 65536 * 2;
int n;
struct treeNode{
	int data;
	int pid;
	int lson(){ return pid<<1; }
	int rson(){ return pid<<1|1; }
}arr[maxn];
void bulid(int pid,int l,int r){
	if(l==r){
		cin >> arr[pid].data;  
		return ;
	}
	int mid = (l+r)/2;
	bulid(pid<<1,l,mid);
	bulid(pid<<1|1,mid+1,r);
	arr[pid].data = arr[pid<<1].data+arr[pid<<1|1].data;
}
void modify(int pid,int l,int r,int x,int v){
	if(l==r){
		arr[pid].data +=v;
		return ;
	}
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,v);
	else
		modify(pid<<1|1,mid+1,r,x,v);
	arr[pid].data = arr[pid<<1].data+arr[pid<<1|1].data;
}
int query(int pid,int l,int r,int x,int y){
	if(x <= l && r<=y ) return arr[pid].data;
	int mid = (l+r)/2,res=0;
	if (x<=mid) res+=query(pid*2,l,mid,x,y);
	if (y>mid) res+=query(pid*2|1,mid+1,r,x,y);
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n ;
	bulid(1,1,n);
	string str;
	int a,b,flag=0;
	while(cin >> str){
		if(str=="End") break;
		cin >> a >> b;
		if(str[0]=='Q') {if(flag++) cout << endl; ;cout << query(1,1,n,a,b);}
		if(str[0]=='S') modify(1,1,n,a,b*-1);
		if(str[0]=='A') modify(1,1,n,a,b);
	}
	return 0;
}