//P1294 高手去散步
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
inline int max(int x,int y){
	return x>y?x:y;
}
int G[21][21];
int m,n,ans;
int flag[21];
void dfs(int x,int y){
	ans = max(ans,y);
	for(int i=1;i<=m;i++)
		if(!flag[i]&&G[x][i]!=-1){
			flag[i]=1;
			dfs(i,y+G[x][i]);
			flag[i]=0;
		}	
}
int main(){
	int a,b,c;
	scanf("%d %d",&m,&n);
	memset(G,-1,sizeof(G));
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		G[a][b]=c;
		G[b][a]=c;
	}
	for(int i=1;i<=m;i++){
		flag[i] = 1;
		dfs(i,0);
		flag[i] = 0;
	}
	printf("%d",ans);
	return 0;
}