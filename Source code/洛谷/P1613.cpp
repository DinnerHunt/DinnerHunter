#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxd = 55;
int G[maxd][maxd],f[maxd][maxd][maxd],d[maxd];
int m,n;
int bfs(){
	memset(d,-1,sizeof(d));
	queue<int> que;
	d[1] = 0;
	que.push(1);
	while(!que.empty())
	{
		int k = que.front(); que.pop();
		for(int i = 1; i<=m ; i++){
			if(G[k][i]&&d[i] == -1)
			{
				d[i] = d[k]+1;
				if(i == m) return d[i];
				que.push(i);
			}
		}
	}
}
int main(){
	int a,b;
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		G[a][b] = 1;
		f[0][a][b] = 1;
	}
	for(int level=1;level<=m;level++)
		for(int i = 1; i <= m ; i++)
			for(int j = 1; j <= m ; j++)
				for(int k = 1; k<=m; k++)
					if(f[level-1][i][k] && f[level-1][k][j]) 
					{
						f[level][i][j] = 1;
						G[i][j] = 1;
					}
    bfs();
	printf("%d",d[m]);
	return 0;
}