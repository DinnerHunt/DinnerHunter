#include <stdio.h>

int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF){
		int j=1,sum=0,flag=0;
		for(int i=2;i<=2*x;i+=2){
			sum+=i;
			if(j==y||i==2*x){
				if(flag++)
					printf(" ");
				printf("%d",sum/j);
				j=1,sum=0;
			}
			else
				j++;
		}
		printf("\n");

	}	
	return 0;
}