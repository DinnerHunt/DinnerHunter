//P1406 方格填数
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
int n,arr[16],sum,ans[16],pd[16];
int h[4],l[4];
int dfs(int x){
	if(x==n*n){
		int k=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
		    if(j==i)k+=ans[i*n+j];
		    if(j+i+1==n)k-=ans[i*n+j];
			}
		if(!k){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j) printf(" ");
                    printf("%d ",ans[i*n+j]);
                }
                printf("\n");
            }
			return 1;
		}
	}
	else
		for(int i=0;i<n*n;i++){
			if(pd[i]) continue;
            if(x%n==n-1&&h[x/n]+arr[i]!=sum)continue;
            if(x/n==n-1&&l[x%n]+arr[i]!=sum)continue;
    			 pd[i] = 1;
    			 h[x/n]+=arr[i];
    			 l[x%n]+=arr[i];
    			 ans[x] = arr[i];
    			 if(dfs(x+1)) return 1;
    			 pd[i] = 0;
    			 h[x/n]-=arr[i];
    			 l[x%n]-=arr[i];
        }
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n*n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sum/=n;
	sort(arr,arr+n*n);
	printf("%d\n",sum);
	dfs(0);
	return 0;
}