#include <stdio.h>

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		int max=0,min=100,sum=0;		
		int number,cout=0;
		while(x--){
			scanf("%d",&number);
			if(max<number)
				max=number;
			if(min>number)
				min=number;
			sum+=number;
			cout++;
		}
		printf("%.2f\n",(number-max-min)*1.0/(cout-2))
	}
	return 0;
}