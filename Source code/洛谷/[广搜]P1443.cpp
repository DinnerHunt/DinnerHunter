//P1443 luogu
//DinnerHunt
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int flag[405][405],m,n,qx,qy;
int fx[8]={-1,1,2,2,-1,1,-2,-2},fy[8]={2,2,1,-1,-2,-2,1,-1};
typedef pair<int,int> P;
queue<P> que;
int main(){
	scanf("%d %d %d %d",&m,&n,&qx,&qy);
	memset(flag,-1,sizeof(flag));
	que.push(P(qx,qy));
	flag[qx][qy]=0;
	while(que.size()){
		P p = que.front();
		que.pop();
		for(int i=0;i<8;i++)
		{
			int x = p.first+fx[i],y=p.second+fy[i];
			if(x>0&&x<=m&&y>0&&y<n&&flag[x][y]==-1)
			{
				que.push(P(x,y));
				flag[x][y]=flag[p.first][p.second]+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++)
		{
			cout << flag[i][j];
			for(int i=0;i<6-(flag[i][j]/10);i++)
				cout << " ";
		}
		endl;
	}
	return 0;
}