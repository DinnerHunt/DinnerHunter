//POJ1979
//Red and Black
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
char G[20][21];
int a,b,sa,sb,ans;
int fx[4]={1,-1,0,0},fy[4]={0,0,-1,1};
void dfs(int x,int y){
	ans++;
	G[x][y]='#';
	for(int i=0;i<4;i++)
		if(x+fx[i]>=0&&x+fx[i]<b&&y+fy[i]>=0&&y+fy[i]<a&&G[x+fx[i]][y+fy[i]]=='.')
			dfs(x+fx[i],y+fy[i]);
	
}
int main(){	
    while(scanf("%d %d",&a,&b)==2&&a&&b){
		ans=0;
		memset(G,0,sizeof(G));
		G[0][0] = getchar();
		for(int i=0;i<b;i++)
			for(int j=0;j<=a;j++){
				scanf("%c",&G[i][j]);
				if(G[i][j]=='@'){
					sa=i;
					sb=j;
				}
			}
		dfs(sa,sb);
		printf("%d\n",ans);
	}
	return 0;
}