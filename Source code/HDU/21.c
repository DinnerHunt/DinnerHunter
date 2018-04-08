#include <stdio.h>

int money(int x){
	int sum=0;
	sum+=x/100;
	x%=100;
	sum+=x/50;
	x%=50;
	sum+=x/10;
	x%=10;
	sum+=x/5;
	x%=5;
	sum+=x/2;
	x%=2;
	sum+=x;
	return sum;
}
int main(){
	int number,flag;
	while(scanf("%d",&number)!=EOF&&number!=0){
		int sum=0;
		while(number--){
			int CNY;
			scanf("%d",&CNY);
			sum+=money(CNY);
		}
		printf("%d",sum);
        printf("\n");
	}
	return 0;
}