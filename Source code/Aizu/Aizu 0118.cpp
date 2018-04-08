//Aizu 0118
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
int w,h,fx[4]={0,0,-1,1},fy[4]={1,-1,0,0},ans;
char G[101][101];
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int a=x+fx[i],b=y+fy[i];
		if(a>=0&&a<h&&b>=0&&b<w&&G[a][b]==G[x][y]){
			G[x][y]=0;
			dfs(a,b);
		}
	}
}
int main(){
	while(scanf("%d %d",&w,&h)==2){	
		ans = 0;
		G[0][0]=getchar();
		memset(G,0,sizeof(G));
		for(int i=0;i<h;i++)
			for(int j=0;j<=w;j++)
				scanf("%c",&G[i][j]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(G[i][j]!=0){
					ans++;
					dfs(i,j);
				}
		printf("%d\n",ans);
	}
	return 0;
}