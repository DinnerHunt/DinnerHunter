## [kuangbin] 专题一 简单搜索
---  

* 2018/4/16
>   *  >POJ 1321 棋盘问题 
>
>   ```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10],b[10],n,m,k,pos;
typedef pair<int,int> P;
P c[100];
char ch;
void dfs(int x,int y){ 	// x搜到第几个位置，y摆了几个棋
	if(x==pos||y==m){
		if(y==m)
			k++;
	}
	else{
		if(a[c[x].first]==-1&&b[c[x].second]==-1){
			a[c[x].first]=1;
			b[c[x].second]=1;
			dfs(x+1,y+1);
			a[c[x].first]=-1;
			b[c[x].second]=-1;
		}
		dfs(x+1,y);
	}
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF&&n!=-1&&m!=-1){
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		k=0,pos=0;
        ch = getchar();
		for(int i=0;i<n;i++)
			for(int j=0;j<=n;j++)
			{
				scanf("%c",&ch);
				if(ch=='#')
					c[pos++] = P(i,j);
			}
		dfs(0,0);
		printf("%d\n",k);
	}
	return 0;
}
 ```
  >
> * > POJ 2251 Dungeon Master  
>
>   ```cpp
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
  ```
 >
 > * > POJ 3278
 >  
>   ```cpp
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,flag[200050];
int main(){
		scanf("%d %d",&n,&m);
		queue<int> que;
		que.push(n);
		flag[n]=1;
		while(!que.empty()){
			int k = que.front();
			que.pop();
			if(k==m) {printf("%d",flag[k]-1);break;}
			if(k<0)
				continue;
			if(k<m){
				if(!flag[k+1]) que.push(k+1),flag[k+1]=flag[k]+1;
				if(k<101000)
				if(!flag[k*2]) que.push(k*2),flag[k*2]=flag[k]+1;
	            if(!flag[k-1]) que.push(k-1),flag[k-1]=flag[k]+1;
			}
			else{
				if(!flag[k-1]) que.push(k-1),flag[k-1]=flag[k]+1;
			}
		}
	return 0;
}
```
> 待完