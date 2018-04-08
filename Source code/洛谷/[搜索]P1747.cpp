//P1747 好奇怪的游戏
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int fx[12] = {-2,-2,-1,1,2,2,2,2,1,-1,-2,-2},
	fy[12] = {1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};
int flag[100][100];
void bfs(int x,int y){
	queue<P> que;
	memset(flag,0,sizeof(flag));
	flag[x][y] = 1;
	que.push(P(x,y));
	while(!que.empty()){
		P p = que.front();
		que.pop();
		for(int i=0;i<12;i++){
			int a = p.first+fx[i];
			int b = p.second+fy[i];
			if(a>100||a<1||b>100||b<1||flag[a][b]) continue;
			if(a==1&&b==1){
				printf("%d",flag[p.first][p.second]);
				return ;
			}
			flag[a][b] = flag[p.first][p.second]+1;
			que.push(P(a,b));
		}

	}

}

int main(){
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	bfs(x1,y1);
	printf("\n");
	bfs(x2,y2);
	return 0;
}