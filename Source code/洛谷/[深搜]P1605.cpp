//P1605 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int flag[7][7];
int x,y,t,ans=0;
int qx,qy,zx,zy,a,b;
int fx[4]={1,-1,0,0},fy[4]={0,0,-1,1};
void bfs(int x,int y){
	if(x==zx&&y==zy){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int x1=x+fx[i],y1=y+fy[i];
		if(!flag[x1][y1])
		{
			flag[x1][y1]=1;
			dfs(x1,y1);
			flag[x1][y1]=0;
		}

	}
}
int main(){
	cin >> x >> y >> t;
	cin >> qx >> qy >> zx >> zy;
	for(int i=0;i<t;i++){
		cin >> a >> b
		flag[a][b] = 1;
	}
	flag[qx][qy]=1;
	bfs(qx,qy);
	cout << ans;
	return 0;
}