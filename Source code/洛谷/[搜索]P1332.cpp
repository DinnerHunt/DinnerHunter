//P1332 血色先锋队
//DinnerHunt
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 505;
int fx[4]={1,-1,0,0},fy[4] = {0,0,1,-1};
typedef pair<int,int> P; 
queue<P> que;
int G[maxn][maxn];
int n,m,a,b;int main(){
	int x,y;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d %d",&x,&y);
		G[x][y] = 1;
		que.push(P(x,y));
	}
	while(!que.empty()){
		P p = que.front();
		que.pop();		
		for(int i=0;i<4;i++){
			int x1 = p.first + fx[i];
			int y1 = p.second + fy[i];
			if(x1>0&&x1<=n&&y1>0&&y1<=m&&!G[x1][y1]){
				G[x1][y1] = G[p.first][p.second] + 1;
				que.push(P(x1,y1));
			}
		}
	}
	for(int i = 0;i < b; i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",G[x][y]-1);
    }
    return 0;
}