//Aizu 0558
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxd = 1005;
typedef pair<int,int> P;
char arr[maxd][maxd];
int flag[maxd][maxd];
int n,m,k,qx,qy,ans;
int fx[] = {1,-1,0,0 }, fy[] = { 0,0,1,-1 }; 
void bfs(){
	ans = 1;
	queue<P> que;
	que.push(P(qx,qy));
	flag[qx][qy] = 1;
	while(!que.empty())
	{
		P p = que.front();que.pop();
		for(int i=0;i<4;i++){
			int x = p.first+fx[i] , y = p.second+fy[i], z = flag[p.first][p.second];
			if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='X'&&!flag[x][y])
			{
				if(arr[x][y] =='0'+ans)
				{   
					if(ans==k){printf("%d\n",z);return;}
                    memset(flag,0,sizeof(flag));
					while(!que.empty()) que.pop();
                    ans++;
                    flag[x][y] = z+1;
				    que.push(P(x,y));
                    break;
				}
				flag[x][y] = z+1;
				que.push(P(x,y));
			}
		}
	}
}
int main(){
	while(scanf("%d %d %d",&n,&m,&k)==3&&n&&m)
	{
		arr[0][0] = getchar();
		for(int i=0;i<n;i++)
			for(int j=0;j<=m;j++)
			{
				arr[i][j] = getchar();
				if(arr[i][j] == 'S') qx=i,qy=j;
			}
		bfs();
	}
	return 0;
}