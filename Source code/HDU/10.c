#include <stdio.h>
#include <math.h>
int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF){
		int flag=1,swap,cout=0;
        if(x>y)
        {
            swap=x;
            x=y;
            y=x;
        }
		for(int i=x;i<=y;i++){
			int j=i,test=0;
			while(j){test+=pow(j%10,3);j/=10;}
			if(test==i){
				if(cout++)
					printf(" ");
				
				printf("%d",i);
				flag=0;
			}
		}
		if(flag)
			printf("no");
        printf("\n");
	}

}