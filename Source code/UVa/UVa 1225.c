//数数字 UVa1225  2017.6.21

#include <stdio.h>
#include <string.h>
int main(){
	int arr[11];
	int x,y;
	scanf("%d",&x);
    while(x--){
        memset(arr,0,sizeof(arr));
        int i,n;
        scanf("%d",&y);
        for(i=0;i<=y;i++){
                int j=i;
                while(j){
                    arr[j%10]+=1;
                    j/=10;
                }
            }
        
        for(n=0;n<10;n++){
            printf("%d ",arr[n]);
        }
        printf("\n");
        }
    
	return 0;
}
