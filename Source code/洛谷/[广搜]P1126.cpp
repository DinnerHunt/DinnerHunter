//P1126 luogu
//DinnerHunt
#include <iostream>
#include <queue>
using namespace std;
int ti[55][55][5];
int arr[55][55];
int n,m,qx,qy,zx,zy,f,k;
typedef struct P{
	int x,y,c;
}P;
P t;
char ch;
queue<P> que; 
int fx[4]={-1,0,1,0},fy[4]={0,1,0,-1};
void bfs(){
	ti[qx][qy][f]=1;
	t.x=qx;
	t.y=qy;
	t.c=f;
	que.push(t);
	while(que.size())
	{
		P p = que.front();
        que.pop();
		int nx = p.x , ny = p.y ,nc = p.c;
		if(nx==zx&&ny==zy){ f=p.c;break;}
		for(int i=1;i<=3;i++){
			t.x=nx+fx[p.c]*i;
			t.y=ny+fy[p.c]*i;
			t.c=p.c;
			if(!ti[t.x][t.y][p.c]&&t.x>0&&t.x<=n&&t.y>0&&t.y<=m&&!arr[t.x][t.y])
			{
				if(!ti[t.x][t.y][p.c]) ti[nx][ny][nc]=ti[nx][ny][nc]+1;
				ti[t.x][t.y][p.c]=ti[nx][ny][nc]+1;
				que.push(t);
			}
		}
		if(!ti[nx][ny][(nc+1)%4])
		{
			ti[nx][ny][(nc+1)%4]=ti[nx][ny][nc]+1;
			t.x=nx;
			t.y=ny;
			t.c=(nc+1)%4;
			que.push(t);
		}
		if(!ti[nx][ny][(nc-1)%4])
		{
			ti[nx][ny][(nc-1)%4]=ti[nx][ny][nc]+1;
			t.x=nx;
			t.y=ny;
			t.c=(nc-1)%4;
			que.push(t);
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
		{
            if(i==0||i==n+1||j==0||j==m+1)
            {
                arr[i][j] =1;
                continue;
            }
			cin >> k;
			if(k==1){
				arr[i][j]=1;
				arr[i][j-1]=1;
				arr[i-1][j]=1;
				arr[i-1][j-1]=1;
			}
		}
	cin >> qx >> qy >> zx >> zy >> ch;
	switch(ch){
		case 'N':
			f=0;
			break;
		case 'E':
			f=1;
			break;
		case 'S':
			f=2;
			break;
		case 'W':
			f=3;
			break;
	}
	bfs();
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++)
            cout << ti[i][j][4] << " ";
        cout << endl;
	}

	return 0;
}