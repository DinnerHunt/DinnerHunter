#include <stdio.h>
#include <stdlib.h>
int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF){
		int a,b,max=0,number;
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++){
				scanf("%d",&number);
				if(abs(number)>abs(max)){
					max=number;
					a=i;b=j;
				}
			}
		printf("%d %d %d\n",a+1,b+1,max);
	}
	return 0;			
}