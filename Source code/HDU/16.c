#include <stdio.h>

int main(){
	int number;
	while(scanf("%d",&number)!=EOF){
		int arr[number],min,flag=0;
		for(int i=0;i<number;i++){
			scanf("%d",&arr[i]);
			if(flag++){
				if(arr[min]>arr[i])
					min=i;
            }
			else
				min=i;
		}
		if(min!=0){
			int swap;
			swap=arr[0];
			arr[0]=arr[min];
			arr[min]=swap;
		}
		flag=0;
		for(int i=0;i<number;i++){
			if(flag++)
				printf(" ");
			printf("%d",arr[i]);
		}
        printf("\n");
	}
	return 0;
}