//正方形 UVa201
#include <stdio.h>
#include <string.h>
int x,y,second=0;
int main(){
	while(scanf("%d %d",&x,&y)==2&&y){
			getchar();
			int arr[x][x];
			int arr2[x][x];
			memset(arr,0,sizeof(arr));
			memset(arr2,0,sizeof(arr));
			while(y--){
				char c;
				int a,b;
				scanf("%c %d %d",&c,&a,&b);
                //printf("%c %d %d\n",c,a,b);
				if(c=='H')
					arr[a-1][b-1]=1;
				else 
					arr2[b-1][a-1]=1;
				getchar();
			}
			/*for(int i=0;i<x;i++){
				for(int j=0;j<x;j++)
					printf("%d", arr2[i][j]);
                printf("\n");
            }*/
			if(second)
				printf("\n**********************************\n");
			printf("Problem #%d\n\n",++second);
			int sum = 0;  
        	for (int l = 0 ; l < n ; ++ l) {  
            	int count = 0,flag = 0;  
            	for (int i = 0 ; i+l < n ; ++ i)  
            	for (int j = 0 ; j+l < n ; ++ j) {  
                	flag = 1;  
                	for (int h = j ; h < j+l ; ++ h)  
                    	if (!arr[i][h] || !arr[i+l][h]) flag = 0;  
                	for (int v = i ; v < i+l ; ++ v)  
                    	if (!arr2[v][j] || !arr2[v][j+l]) flag = 0;  
                	count += flag;  
            }  
            sum += count;  
            if (count) printf("%d square (s) of size %d\n",count,l);  
        }  
              
        if (!sum) printf("No completed squares can be found.\n");  
    }   
	return 0;
}