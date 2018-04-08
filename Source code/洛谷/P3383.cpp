//P3383 luogu
//DinnerHunt
#include <stdio.h>
int arr[10000000];
int N,M;
void init(){
	for(int i=2;i*i<=N;i++)
		if(arr[i])
			for(int j=i*2;j<=n;j+=i)
				arr[j] = 0;
}
int main(){
	scanf("%d %d",&N,&M);
	int k;
	init();
	for(int i=0;i<M;i++){
		scanf("%d",&k);
		if(arr[k])printf("Yes");
		else printf("No");
	}
	return 0;
}