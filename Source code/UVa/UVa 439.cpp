//UVa536
//Knight Moves 骑士的移动
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int flag[10][10];
int fx[8]={2,2,1,-1,-2,-2,-1,1},fy[8] = {-1,1,2,2,1,-1,-2,-2};
int nx,ny,zx,zy;
void bfs(){
	queue<P> que;
	que.push(P(nx,ny));
	flag[nx][ny] = 0;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i=0;i<8;i++){
			int m = x+fx[i],n = y+fy[i];
			if(m>0&&m<=8&&n<=8&&n>0)
				if(flag[m][n]==-1){
					flag[m][n] = flag[x][y]+1;
					if(m==zx&&n==zy) return;
					que.push(P(m,n));
				}
		}
		
	}
}
int main(){
	char ch1[2],ch2[2];
	int flag=0;
	while(scanf("%s %s",ch1,ch2)==2){
		memset(flag,-1,sizeof(flag));
		nx = ch1[0]-'a'+1;
		ny = ch1[1]-'0';
		zx = ch2[0]-'a'+1;
		zy = ch2[1]-'0';
		bfs();
		if(flag++) printf("\n");
		printf("To get from %s to %s takes %d knight moves.",ch1,ch2,flag[zx][zy]);
	}
	return 0;
}