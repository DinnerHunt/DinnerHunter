#include <stdio.h>
#include <stdlib.h>
int cmp(const void* x,const void* y){
	return *(int*)y-*(int*)x;

}
int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF){
		if(x==y==0)
			break;
		int arr[x];
        int i=0;
		for(;i<x;i++)
			scanf("%d",&arr[i]);
		arr[i++]=y;
		qsort(arr,i,sizeof(int),cmp);
		while(i--){
			if(i==0)
				printf("%d",arr[i]);
			else 
				printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}