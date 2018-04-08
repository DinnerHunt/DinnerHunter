//UVa 524
//Prime Ring Problem 素数环
//DinnerHunt
#include <cstdio>
using namespace std;
int n;
int prime[40],arr[20],flag[20];
void init(){
	for(int i=2;i<40;i++)
		prime[i]=1;
	for(int i=2;i*i<40;i++)
		if(prime[i])
			for(int j=i*i;j<40;j+=i)
				prime[j] = 0;
}
void dfs(int k){
	if(k==n+1&&prime[arr[n]+arr[1]]){
	    printf("1");
		for(int i=2;i<=n;i++) printf(" %d",arr[i]);
		printf("\n"); 
	}
	else 
		for(int i=2;i<=n;i++)
			if(!flag[i]&&prime[i+arr[k-1]]){
				arr[k] = i;
				flag[i] = 1;
				dfs(k+1);
				flag[i] = 0;
			}
}
int main(){
	int count = 0;
	init();
	while(scanf("%d",&n)==1&&n){
		if(count) printf("\n");
		printf("Case %d:\n",++count);
        arr[1]=1;
		dfs(2);
	}
	return 0;
}
