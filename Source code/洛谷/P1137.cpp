#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 100005;
struct node{
	int v,next;
}e[2*maxd];
int n,m,f[maxd],eid,d[maxd],ans;
void init(){
	memset(f,-1,sizeof(f));
	eid=0;
}
void insert(int x,int y){
	e[eid].v = y;
	e[eid].next = f[x];
	f[x] = eid++;
};
int dfs(int x){
	if(d[x]) return d[x];
	d[x] = 1;
	for(int i = f[x];i+1;i=e[i].next)
		d[x] = max(d[x],dfs(e[i].v)+1);
	return d[x];
}
int main(){
	int a,b;
	scanf("%d %d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		insert(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(!d[i]) d[i] = dfs(i);
		printf("%d\n",d[i]);
	}
	return 0;
}