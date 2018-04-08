//UVa 1600
//巡逻机器人 Patrol Robot
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 25;
typedef pair<int,int> P;								//BFS时存的是左边 x,y所以 需要能储存两个值的结构
int flag[maxn][maxn],G[maxn][maxn],za[maxn][maxn];		//到点的步数，储存每个点值，储存到每个点时已连续越过障碍的数量
int fx[4] = {0,0,1,-1},fy[4] = {1,-1,0,0};				//4个方位
int n,m,k;												//矩形大小和障碍数量限制
void bfs(){
	queue<P> que;
	que.push(P(1,1));									//将起点放入队列进行BFS
	flag[1][1]=0;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
        //printf("%d %d\n",x,y);
		que.pop();
		if(x==n&&y==m)break;							//到终点了即可退出
		for(int i=0;i<4;i++){							//遍地4个方位
			int a = x+fx[i], b= y+fy[i];				
			if(G[a][b]){								//因为可能出现后面绕远路，使得原本无法通过的点可以通，因此za[a][b]的值在第一次后是可以变的
				if(!za[a][b]) za[a][b] = 1+za[x][y];	//（感觉有数据可以过这部分，因为下面flag==-1，但没想出来，就决定不想了,方正能过,逃）
				else za[a][b] = min( 1+za[x][y],za[a][b]);
			}
			if(a>=1&&a<=n&&b>=1&&b<=m)					//不越界
				if(flag[a][b]==-1){						//没访问过
					if(za[a][b] <= k){					//不过障碍限制
						flag[a][b]=flag[x][y]+1;		//距离+1
						que.push(P(a,b));
					}
				}
		}
	}
	printf("%d\n",flag[n][m]);							//输出到达终点的步数
}
int main(){
	int count;
	scanf("%d",&count);
	while(count--){
		memset(flag,-1,sizeof(flag));		//每次测试开始前的格式化
		memset(za,0,sizeof(za));
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&G[i][j]);
		bfs();
	}
	return 0;
}

2017/12/4

思路

从左上到右下，可以用BFS遍地来完成，唯一麻烦的一点就是障碍的问题
障碍这里我们可以用一个数组来储存连续经过障碍的数量
如果下一个点有障碍，就看看当前点越过障碍的数量加1是否会大于越过障碍的限制，如果大于则不能行走
然后模拟出来

代码构造

读图 然后 BFS，输出到终点的值；具体构造看代码注释