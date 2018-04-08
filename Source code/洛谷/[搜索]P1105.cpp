//P1105 平台
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int h,l,r,id;
	node(){
		h=0;l=0;r=0,id=0;
	}
}arr[1005];
bool less1(const node &a,const node &b){
	return (a.h<b.h)||(a.h==b.h&&a.id>b.id);
}
bool less2(const node &a,const node &b){
    return a.id<b.id;
}
int dfs(int d,int x){
    if(d<=0) return 0;
    if(arr[d].l<x&&arr[d].r>x) return arr[d].id;
    return dfs(d-1,x);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d %d",&arr[i].h,&arr[i].l,&arr[i].r);
		arr[i].id = i;
	}
	sort(arr+1,arr+n+1,less1);
	for(int i=n;i>0;i--){
		arr[i].l = dfs(i-1,arr[i].l);
        arr[i].r = dfs(i-1,arr[i].r);
	}
    sort(arr+1,arr+n+1,less2);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",arr[i].l,arr[i].r);
    
	return 0;
}