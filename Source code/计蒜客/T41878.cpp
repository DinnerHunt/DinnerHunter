#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int tree[maxn],a[maxn];
int n,d;
int lowbit(int x){
	return x&-x;
}
void change(int r){
	tree[r] = a[r];
	for(int i=1;i<lowbit(r);i<<=1)
		tree[r] = max(tree[r],tree[r-i]);
}
int getmax(int l,int r){
	int ret = a[r];
	while(l<=r){
		ret = max(ret,a[r]);
		for(--r;r-l>lowbit(r);r-=lowbit(r))
			ret = max(ret,tree[r]);
	}
	return ret;
}
int main(){
	char ch;
	int k,j=0,leng=0;
	scanf("%d %d",&n,&d);
	while(n--){
		cin >> ch;
		scanf("%d",&k);
		if(ch=='Q'){
			j=getmax(leng-k+1,leng);
			printf("%d\n",j);
		}
		else{
			leng++;
			a[leng] = (k+j)%d;
			change(leng);
		}
	}
	return 0;
}