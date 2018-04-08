#include<stdio.h>
typedef struct P
{
	int x,y;
}P;
P f[1000][1000];
P t;
int s[1000][1001];
int v[1000][1000];
char map[1000][1000];
int num,nx,ny;
int M,N;
void dfs(int x,int y)
{
	if(x<0||y<0||x==N||y==N)return;
	num++;
	f[x][y]=t;
	v[x][y]=1;
	if(map[x][y]==49)
	{
		if(map[x+1][y]==48&&!v[x+1][y])
		dfs(x+1,y);
		if(map[x][y+1]==48&&!v[x][y+1])
		dfs(x,y+1);
		if(map[x-1][y]==48&&!v[x-1][y])
		dfs(x-1,y);
		if(map[x][y-1]==48&&!v[x][y-1])
		dfs(x,y-1);
	}
	if(map[x][y]==48)
	{
		if(map[x+1][y]==49&&!v[x+1][y])
		dfs(x+1,y);
		if(map[x][y+1]==49&&!v[x][y+1])
		dfs(x,y+1);
		if(map[x-1][y]==49&&!v[x-1][y])
		dfs(x-1,y);
		if(map[x][y-1]==49&&!v[x][y-1])
		dfs(x,y-1);
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%s",map[i]);
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(!v[i][j])
			{
				num=0;t.x=i;t.y=j;
				dfs(i,j);
				s[i][j]=num;
			}
		}
	}
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&nx,&ny);
		printf("%d\n",s[f[nx-1][ny-1].x][f[nx-1][ny-1].y]);
	}
}
