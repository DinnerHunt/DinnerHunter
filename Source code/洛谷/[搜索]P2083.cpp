//luogu P2083 找人
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int,int> P;
inline int min(int x,int y){
	return x<y?x:y;
}
inline int abs(int x){
	return x<0?-x:x;
}
P G[1005][105];
int flag[1005][105],ans=9999999,v;
void dfs(int x,int y,int k){
    flag[x][y]=1;
    //printf("%d %d %d %d %d\n",x,y,G[x][y].first,G[x][y].second,k);
	if(G[x][y].first==x&&G[x][y].second==y){
		ans = min(ans,k);
        return;
    }
    if(flag[G[x][y].first][G[x][y].second])
        return;
	dfs(G[x][y].first,G[x][y].second,k+abs(G[x][y].first-x)*v);
}
int main(){
	int n,m,x,y;
	scanf("%d %d %d %d %d",&n,&m,&v,&x,&y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d %d",&x,&y);
            G[i][j].first = x;
            G[i][j].second = y;
        }
	for(int i=1;i<=m;i++){
		memset(flag,0,sizeof(flag));
		dfs(1,i,0);
	}
    if(ans == 9999999)
        printf("impossible");
   	else
		printf("%d",ans);
	return 0;
}