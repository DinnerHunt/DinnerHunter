//T37716 取石子游戏 jisuanke
//DinnerHunt
#include <stdio.h>
int n,a,b,c;
int gcd(int x,int y){
	if(y) return gcd(y,x%y);
	return x;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		if((a/gcd(b,c))%2) printf("huaye");
		else printf("suantou");
		if(n) printf("\n");
	}
	return 0;
}