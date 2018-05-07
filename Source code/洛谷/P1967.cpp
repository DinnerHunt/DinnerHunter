#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 50005;
const int maxn = 10005;
struct node{
	int to,next,cost;
}e[maxn];
struct edge{
	int x,y,z;
	bool operator < (const edge &other) const {
		return z > other.z;
	}
}arr[maxd];
int fa[maxn],d[maxn],f[maxn];
int m,n,eid;
typedef pair<int,int> P;

P bz[maxn][20];
void init(){
    memset(d,-1,sizeof(d));
    memset(f,-1,sizeof(d));
    for(int i=0;i<=m;i++)
    	for(int j=0;j<20;j++)
    		bz[i][j].second = 1e9;
    eid=0;
    for(int i =0;i<=m;i++)
        fa[i] = i;
}
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x] = gf(fa[x]); 
}
void until(int x,int y){
	fa[gf(x)] = gf(y);
}
void insert(int x,int y,int z){
	e[eid].to = y;
	e[eid].cost = z;
	e[eid].next = f[x]; 
	f[x] = eid++;
}
void kruskal(){
	for(int i=0;i<n;i++)
		if(gf(arr[i].x)!=gf(arr[i].y)){
			insert(arr[i].x,arr[i].y,arr[i].z);
			insert(arr[i].y,arr[i].x,arr[i].z);
			until(arr[i].x,arr[i].y);
		}
}
void dfs(int node){
	for(int i = f[node]; i+1; i = e[i].next)
		if(d[e[i].to] == -1)
		{
			d[e[i].to] = d[node] + 1;
			bz[e[i].to][0] = P(node,e[i].cost);
			dfs(e[i].to);
		}	
}
void udouble(){
	for(int level = 1; (1<<level) <= m;level++)
		for(int i = 1; i<=m ; i++){
			bz[i][level] = P(bz[ bz[i][level-1].first ][level-1].first,min(bz[ bz[i][level-1].first ][level-1].second,bz[i][level-1].second));
			//printf("%d %d %d\n",i,level,bz[i][level].second);
		}
}
int lca(int x,int y){
	int i,j,k=1e9;
	if(d[x] < d[y])
	{
	    x+=y;
	    y=x-y;
	    x-=y;
	}
	for(i=0; (1<<i) <= d[x]; i++);
	i--;
	for(j=i;j>=0;j--)
		if(d[y] + (1<<j) <= d[x]){
			k = min(bz[x][j].second,k);
			x = bz[x][j].first;
		}
	if(x==y) return k;
	
	for(j = i;j>=0;j--)
		if(bz[x][j].first != bz[y][j].first)
		{
			k = min(k,min(bz[x][j].second,bz[y][j].second));
			x=bz[x][j].first;
			y=bz[y][j].first;
		}
		
	k = min(k,min(bz[x][0].second,bz[y][0].second));
	return k;
}
int main(){
	int a,b,root;
	scanf("%d %d",&m,&n);
    init();
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
	sort(arr,arr+n);
	kruskal();
	
	for(int i=1;i<=m;i++)
		if(d[i]==-1)
		{   
	        d[i] = 0;
	        dfs(i);
	    }
	udouble();
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(gf(a)!=gf(b)) printf("-1\n");
		else printf("%d\n",lca(a,b));
	}
	
	return 0;
}