#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,G[20][20],ans;
int qx,qy;
int fx[4]={0,0,1,-1},fy[4]={1,-1,0,0};
void dfs(int x,int y,int z){
	if(z>=ans) return;
	for(int i=0;i<4;i++)
	{
		int a=x+fx[i],b=y+fy[i];
		if(a>=0&&a<=n&&b>=0&&b<=m&&G[a][b]!=1)
		{
			while(!G[a][b])
			{ 
				if(G[a][b]==3)
					{ 
						ans = min(z,ans);  return;
					}   
					a+=fx[i],b+=fy[i]; 
			}
			G[a][b] = 0;
			dfs(a-fx[i],b-fy[i],z+1);
			G[a][b] = 1;
		}
	}
}
int main{
	while(scanf("%d %d",&m,&n)==2)
	{
		ans = 11;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",G[i][j]);
				if(G[i][j]==2) qx=i,qy=j;
			}
		dfs(qx,qy,0);
		if(ans==11) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
