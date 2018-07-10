#include <cstdio>
#include <iostream>
using namespace std;
char G[100][100];
int fx[4] = {1,0,-1,0},fy[4] = {0,1,0,-1};
int n,m,ans;
void dfs(int x,int y)
{
	G[i][j] = '.';
	for(int i=0;i<4;i++)
	{
		int a = x+fx[i],b=y+fy[i];
		if(a>=0&&a<x&&b>=0&&b<y&&G[a][b] == '#')
			dfs(a,b);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> G[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(G[i][j] == 'W')
			{
				ans++;
				dfs(i,j);
			}
	printf("%d",ans);
	return 0;
}