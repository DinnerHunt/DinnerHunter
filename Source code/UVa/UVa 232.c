//纵横字谜的答案 UVa 227 
#include <stdio.h>
#include <string.h>
int main(){
	int x,y,number=0,m=0;
	while(scanf("%d %d",&x,&y)==2){
		getchar();
		char arr[x][y];
		int arr1[x][y];
		memset(arr1,0,sizeof(arr1));
		int i=0,j,hunt=0;
		while(i<x)
			gets(arr[i++]);
		for(i=0;i<x;i++)
			for(j=0;j<y;j++){
					if(arr[i][j]!='*'){
						if(i==0||j==0||arr[i-1][j]=='*'||arr[i][j-1]=='*')
							arr1[i][j]=++hunt;
                        
					}
			}
        if(m!=0)
            printf("\n");
        m=1;
		printf("puzzle #%d:\nAcross\n",++number);
		int n=0;
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(arr[i][j]=='*'){
                    if(n==1){
					    printf("\n");
					    n=0;
                    }
				}
				else{
					if(n==0){
						printf("%3d.",arr1[i][j]);
						n=1;
					}
					printf("%c",arr[i][j]);
				}
            }
            if(n!=0){
            printf("\n");
            n=0;}
        }
        printf("Down\n");
		for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                if(arr[i][j]!='*'){
                    if(i==0||arr[i-1][j]=='*'){
                        printf("%3d.",arr1[i][j]);
                        int b=i;
                        while(b<x){
                            if(arr[b][j]=='*')break;
                            printf("%c",arr[b++][j]);
                        }
                        printf("\n");
                    }
                }
            }
        }
	}
	return 0;
}