//P1403 luogu
//DinnerHunt
#include <cstdio>
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans+=n/i;
	}
	printf("%lld",ans);
	return 0;
}