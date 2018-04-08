#include <stdio.h>
#include <math.h>
int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		int sum=0,sum2=0,swap;
		if(x>y){
			swap=x;
			x=y;
			y=swap;
		}
		for(x;x<=y;x++){
			if(x%2==1)
				sum+=pow(x,3);
			else 
				sum2+=pow(x,2);
		}
		printf("%d %d\n",sum2,sum);
	}
	return 0;
}