//P2128 赤壁之战
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxd = 505;
inline int max(int x,int y){
	return x>y?x:y;
}
int arr[maxd],G[maxd][maxd],flag[maxd],ans;
int n,m,a,b
void dfs(int x,int sum){
	ans = max(ans,sum)
	int k = 1;
	for(int i=1;i<=n;i++)
		if(flag[i]&&!G[x][i])
		{
			k=0;
			break;
		}
	if(k)
	{
		flag[x]=1;
		dfs(x+1,sum+arr[x]);
		flag[x]=0;
	}
	dfs(x+1,sum);
	
}
;int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		flag[i] = arr[i];
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}