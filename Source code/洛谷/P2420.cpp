#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxd = 100005;
struct edge{
	int v,to,cost;
}e[2*maxd];
int eid,f[maxd],d[maxd],n,m,xo[maxd];
void init(){
	memset(f,-1,sizeof(f));
	memset(d,-1,sizeof(d));
	eid = 0;
}
void insert(int x,int y,int z){
	e[eid].cost = z;
	e[eid].v = y;
	e[eid].to = f[x];
	f[x] = eid++; 
}

void dfs(int x){
	for(int i=f[x];i+1;i=e[i].to)
		if(d[e[i].v] == -1)
		{
			if(!d[x]) xo[e[i].v] = e[i].cost;
			else xo[e[i].v]  = xo[x]^e[i].cost;
			d[e[i].v] = d[x]+1;
			dfs(e[i].v);
		}
}
int main(){
	int a,b,c;
	init();
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		insert(a,b,c);
		insert(b,a,c);
	}
	for(int i=1;i<=n;i++)
		if(d[i]==-1)
		{
			d[i]=0;
			dfs(i);
		}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",xo[a]^xo[b]);
	}
	return 0;
}