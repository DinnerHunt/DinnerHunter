//P1146 硬币翻转
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int x,arr[100];
	memset(arr,0,sizeof(arr));
	scanf("%d",&x);
	printf("%d\n",x);
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
		    if(j!=i)arr[j]^=1;
			printf("%d",arr[j]);
		}
		printf("\n");
	}
	return 0;
}