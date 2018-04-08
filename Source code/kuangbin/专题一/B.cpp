#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
char G[40][40][40],ch;
int a,b,c,flag[40][40][40],qx,qy,qz,zx,zy,zz;
int fx[6]={1,-1,0,0,0,0},fy[6]={0,0,-1,1,0,0},fz[6]={0,0,0,0,1,-1};
struct node{
	int x,y,z;
}nod;
void bfs(){
    queue<node> que;
	nod.x=qx;
	nod.y=qy;
	nod.z=qz;
	que.push(nod);
	flag[qx][qy][qz] = 0;
	while(!que.empty()){
		node nod1 = que.front();
		que.pop();
		for(int i=0;i<6;i++){
			int x=nod1.x+fx[i],y=nod1.y+fy[i],z=nod1.z+fz[i];
			if(x>=0&&x<a&&y>=0&&y<b&&z>=0&&z<c&&flag[x][y][z]==-1&&G[x][y][z]!='#'){
				if(x==zx&&y==zy&&z==zz){
					printf("Escaped in %d minute(s).\n",flag[nod1.x][nod1.y][nod1.z]+1);
					return;
				}
				nod.x=x;
				nod.y=y;
				nod.z=z;
				que.push(nod);
				flag[x][y][z] = flag[nod1.x][nod1.y][nod1.z]+1;
			}
		}
	}
	printf("Trapped!\n");
}
int main(){
	while(scanf("%d %d %d",&a,&b,&c)!=EOF&&a&&b&&c){
		memset(flag,-1,sizeof(flag));
		ch = getchar();
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++)
				{
					scanf("%c",&G[i][j][k]);
					if(G[i][j][k]=='S')
						qx=i,qy=j,qz=k;
					if(G[i][j][k]=='E')
						zx=i,zy=j,zz=k;
				}
				ch = getchar();
			}
            ch = getchar();
        }
		bfs();
	}
	return 0;
}