#include <stdio.h>
#include <stdlib.h>
int cmp(const void* x,const void* y){
	return abs(*(int *)y)-abs(*(int *)x);

}
int main(){
	int number;
	while(scanf("%d",&number)!=EOF){
		int arr[number],flag=0;
		for(int i=0;i<number;i++){
			scanf("%d",&arr[i]);
		}
		qsort(arr,number,sizeof(int),cmp);
		for(int i=0;i<number;i++){
			if(flag++)
				printf(" ");
			printf("%d",arr[i]);
		}
		printf("\n");

	}
	return 0;
}