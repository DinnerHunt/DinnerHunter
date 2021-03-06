//UVa 1601
//The Morning after Halloween 万圣节后的早晨
//DinnerHunt
#include <cstdio>
#include <queue>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 150;
int s[3],t[3];
int G[maxn][5],size[maxn];
int fx[]={1,-1,0,0,0},fy[]={0,0,1,-1,0};
int d[maxn][maxn][maxn];
struct node{
	int v[3];
	int flag;
};
inline int abs(int x){
	return x<0?-x:x;
}
inline bool conflict(int a, int b, int a2, int b2) {
  return a2 == b2 || (a2 == b && b2 == a);
}
int bfs(){
	memset(d,0,sizeof(d));
	queue<node> que;
	node start,stop;
	start.flag = 1;
	stop.flag = -1;
	for(int i=0;i<3;i++){
		start.v[i] = s[i];
		stop.v[i] = t[i];
	}
	que.push(start);
	que.push(stop);
	d[s[0]][s[1]][s[2]] = 1;
	d[t[0]][t[1]][t[2]] = -1;
	while(!que.empty()){
		node n = que.front();
        que.pop();
		int a = n.v[0],b = n.v[1],c=n.v[2],f=n.flag;
		for(int i=0;i<size[a];i++){
			int na = G[a][i];
			for(int j=0;j<size[b];j++){
				int nb = G[b][j];
				if(conflict(a,b,na,nb)) continue;
				for(int k=0;k<size[c];k++){
					int nc = G[c][k];
					if(conflict(a,c,na,nc)) continue;
					if(conflict(b,c,nb,nc)) continue;
					else if(f==1&&d[na][nb][nc]>0) continue;
					else if(f==-1&&d[na][nb][nc]<0)continue;
					else if(!d[na][nb][nc]){
						n.v[0]=na;n.v[1]=nb;n.v[2]=nc;
						n.flag = f;
						d[na][nb][nc] = d[a][b][c]+n.flag;
						que.push(n);
					}
					else return abs(d[a][b][c])+abs(d[na][nb][nc])-1;
				}
			}
		}
    }
}

int main(){
	char lattice[20][20];
	int n,m,number;
	while(scanf("%d %d %d\n",&n,&m,&number)==3&&n){
        //printf("%d %d %d\n",n,m,number);
		for(int i=0;i<m;i++) fgets(lattice[i],20,stdin);
        int cnt=0,x[maxn],y[maxn],id[20][20];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(lattice[i][j]!='#'){
             	x[cnt] = i;y[cnt] = j;id[i][j] = cnt;
             	if(islower(lattice[i][j])) s[lattice[i][j]-'a'] = cnt;
             	else if(isupper(lattice[i][j])) t[lattice[i][j]-'A'] = cnt;
             	cnt++;
            }
        for(int i=0;i<cnt;i++){
        	size[i] = 0;
        	for(int j=0;j<5;j++){
        		int nx = x[i]+fx[j],ny = y[i]+fy[j];
        		if(lattice[nx][ny]!='#')G[i][size[i]++]=id[nx][ny];
        	}
        }
       	if(number<=2) {size[cnt] = 1;G[cnt][0] = cnt;s[2]=t[2]=cnt++;}
       	if(number<=1) {size[cnt] = 1;G[cnt][0] = cnt;s[1]=t[1]=cnt++;}
       	printf("%d\n",bfs());
	}
	return 0;
}