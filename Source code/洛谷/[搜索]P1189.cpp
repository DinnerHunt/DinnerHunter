#include <cstdio>
#include <queue>
using namespace std;
char G[55][55];
int dire[1005],qx,qy;
int fx[4] = {0,1,0,-1},fy[4] = {-1,0,1,0};
struct node{
	int x,y,step;
}
void bfs(){
	queue<node> que;
	node nod;
	nod.x = qx;
	nod.y = qy;
	nod.step=0;
	que.push(nod);
	while(!que.empty()){
		nod = que.front();
		que.pop();

		int z=nod.step,x = nod.x+fx[z],y = nod.y+fy[z];
		while(x<m&&x>=0&&y<n&&y>=0&&G[x][y]!='X'){
			nod.x = x;
			nod.y = y;
			nod.step=z+1;
			que.push(nod);
			x+=fx[z];
			y+=fy[z];
		}
	}
}
int main(){
	int m,n,z;
	char str[10];
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
		getline(stdio,G[i]);
	scanf("%d",z);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(G[i][j]=='*') { qx=i; qy=j; }
	for(int i=0;i<z;i++){
		scanf("%s",str);
		switch(str[0]){
			case 'E': dire[i]=0; break;
			case 'S': dire[i]=1; break;
			case 'W': dire[i]=2; break;
			case 'N': dire[i]=3; break;
		}
	}
	bfs();
	return 0;
}