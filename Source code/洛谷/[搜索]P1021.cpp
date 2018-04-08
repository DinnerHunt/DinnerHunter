//luogu 1021 邮票面值设计
//DinnerHunt
//参考 neymar_jr
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1000],f[40],b[40],n,k,ans;
const int INF = 1<<31-1;
inline int min(int x,int y){
	return x<y?x:y;
}
void dfs(int x){
	if(x==k){
		memset(dp,0,sizeof(dp));
		int i=0;
		while(dp[i]<=n){
			i++;
			dp[i] = INF;
			for(int j=0;j<k&&i-f[j]>=0;j++)
				dp[i] = min(dp[i],dp[i-f[j]]+1);
		}
		if(i-1>ans){
			for(int j=0;j<k;j++)
				b[j] =f[j];
			ans = i-1;
		}
		return;
	}
	for(int i=f[x-1]+1;i<=f[x-1]*n+1;i++)
	{
		f[x] = i;
		dfs(x+1);
	}
}
int main(){
	scanf("%d %d",&n,&k);
	f[0] = 1;
	dfs(1);
	for(int i=0;i<k;i++){
		if(i) printf(" ");
		printf("%d",b[i]);
	}
	printf("\nMAX=%d",ans);
	return 0;
}