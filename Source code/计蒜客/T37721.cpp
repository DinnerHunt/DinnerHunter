//T37721 jisuanke 互质数个数
//DinnerHunt
#include <stdio.h>
int euler(int n){
	int res = n,a=n;
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			res = res/i*(i-1);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) res = res/a*(a-1);
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	n=euler(n);
	printf("%d",n);
	return 0;
}