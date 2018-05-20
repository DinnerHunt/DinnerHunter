#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 500005;
struct edge{
	int v,to;
}e[maxd*2];
int eid,f[maxd],fa[maxd][20],d[maxd];

int a,b,c;
void init(){
	memset(f,-1,sizeof(f));
	eid = 0;
}
int insert(int x,int y){
	e[eid].v = y;
	e[eid].to = f[x];
	f[x] = eid++; 
}
void dfs(int x){
	for(int i = f[x];i+1;i=e[i].to)
		if(!d[e[i].v]){
			d[e[i].v] = d[x]+1;
			fa[e[i].v][0] = x;
			dfs(e[i].v);  
		}
}
void double(){
	for(int level = 1;(1<<level) <= a ;level++)
		for(int i=0)
}
int main(){
	scanf("%d %d %d",&a,&b,&c);
	return 0;
}