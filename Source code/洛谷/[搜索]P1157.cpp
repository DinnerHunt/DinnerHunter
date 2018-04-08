//P1157 组合的输出
//DinnerHunt
#include <cstdio>
using namespace std;
int x,y,arr[25];
int main(){
	scanf("%d %d",&x,&y);
	for(int i=0;i<25;i++) arr[i] = i;
	while(!arr[0]){
		for(int i=1;i<=y;i++)
			printf("%3d",arr[i]);
        printf("\n");
        int j = y;
        while(arr[j]==x-y+j) j--;
        arr[j]++;
        while(j<y) arr[++j]= arr[j-1]+1;
	}
	return 0;
}