//T41864 jisuanke 公告板
//DinnerHunt
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2000000;
typedef pair<int,int> P;
P arr[maxn];
int h,w,n,now=1;
void up(int p){
    if(arr[p<<1].first>=arr[p<<1|1].first)
        arr[p].first=arr[p<<1].first;
    else 
        arr[p].first = arr[p<<1|1].first;
}
void build(int p,int l,int r){
	if(l==r){
		arr[p].first = w;
		arr[p].second = now++;
		return;
	}
	int mid = (l+r)/2;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	up(p);
}
void modify(int p,int l,int r,int z){
	if(l==r){
        printf("%d\n",arr[p].second);
		arr[p].first -=z;
		return;
	}
	int mid = (l+r)/2;
	if(z<=arr[p<<1].first)
		modify(p<<1,l,mid,z);
	else if(z<=arr[p<<1|1].first)
		modify(p<<1|1,mid+1,r,z);
	else{
		printf("-1\n");
		return;
	}
	up(p);
}
int main(){
    scanf("%d %d %d",&h,&w,&n);
	int k;
	build(1,1,h);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		modify(1,1,h,k);
	}
	return 0;
}