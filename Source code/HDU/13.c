#include <stdio.h>

int main(){
	int x;
	while(scanf("%d",&x)){
		int sum=1;
		while(--x){
			sum=sum*2+1;
		}
		printf("%d\n",sum);
	}
	return 0;
}