#include <stdio.h>
#include <string.h>
int arr[50][50];

void init(){
	arr[1][1]=1;
	for(int i=2;i<50;i++)
		for(int j=1;j<=i;j++)
			arr[i][j]=arr[i-1][j]+arr[i-1][j-1];

}

int main(){
	memset(arr,0,sizeof(arr));
	init();
	int number,flag=0;
	while(scanf("%d",&number)!=EOF){
		
		for(int i=1;i<=number;i++){
			for(int j=1;j<=i;j++){
				if(j!=1)
					printf(" ");
				printf("%d",arr[i][j]);
			}
            printf("\n");
		}
        	printf("\n");
	}	
	return 0;
}