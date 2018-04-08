#include <stdio.h>

int main(){
	
	int x;
	while(scanf("%d",&x)!=EOF){
		int a,b,c;
		double y;
		a=b=c=0;
		while(x--){
			scanf("%lf",&y);
			if(y<0)
				a++;
			else if(y==0)
				b++;
			else 
				c++;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}