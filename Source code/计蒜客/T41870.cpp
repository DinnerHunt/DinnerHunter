//jisuanke 棋子等级 T41870
//DinnerHunt
#include<stdio.h>
const int maxn = 100005;
int arr[maxn],tree[maxn];
int n;
int lowbit(int x){
	return x&(-x);
}
int modify(int x,int k){
	for(;x<=maxn;x+=lowbit(x))
		tree[x]+=k;
}
int query(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res+=tree[x];
	return res;
}
int main(){
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		arr[query(x+1)]++;
		modify(x+1,1);
	}
	for(int i=0;i<n;i++){
        if(i) printf("\n");   
		printf("%d",arr[i]);
    }
	return 0;
}