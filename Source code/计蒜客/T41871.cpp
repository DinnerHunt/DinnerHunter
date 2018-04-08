//jisuanke T41871 木桩涂涂看
//DinnerHunt
#include <stdio.h>
const int maxn = 100005;
int arr[maxn];
int n,a,b;
int lowbit(int x){
	return x&-x;
}
void modify(int x,int k){
	for(;x<=n;x+=lowbit(x))
		arr[x]+=k;
}
int query(int x){
	int ans=0;
	for(;x;x-=lowbit(x))
		ans+=arr[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		modify(a,1);
		modify(b+1,-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)printf(" ");
		printf("%d",query(i));
	}
	return 0;
}