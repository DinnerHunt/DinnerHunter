#include <stdio.h>
int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		int sum=1,y;
		while(x--){
			scanf("%d",&y);
			if(y%2==1)
				sum*=y;
		}
		printf("%d\n",sum);
	}
	return 0;
}