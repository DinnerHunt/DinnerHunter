#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int maxd = 10005;
const int inf = 1e9;
struct node{
	int v,next;
}e[maxd];
int f[2*maxd],arr[2*maxd],eid;
int belong[2*maxd],fpn[2*maxd],low[2*maxd],value[2*maxd],que[2*maxd];
bool inq[2*maxd],flag[2*maxd],vis[2*maxd];
int n,p,r,scc,idx,ans,top;
void init(){
	memset(f,-1,sizeof(f));
	memset(vis,false,sizeof(vis));
	memset(flag,false,sizeof(flag));
	memset(inq,false,sizeof(inq));
	eid = 0;
}
void insert(int x,int y){
    e[eid].v= y;
    e[eid].next = f[x];
    f[x] = eid++;
}
void tarjan(int x){
	low[x] = fpn[x] = ++idx;
	que[top++] = x;
	inq[x] = true;
	for(int i=f[x];i+1;i=e[i].next)
	{
		int v = e[i].v;
		if(!fpn[v])
		{
			tarjan(v);
			low[x] = min(low[x],low[v]);
		}
		else if(inq[v])
			low[x] = min(low[x],fpn[v]);
	}
	
	if(low[x] == fpn[x])
	{
		++scc;		
		value[scc] = inf;
		do{

			belong[que[--top]] = scc;
			inq[que[top]] = false;
			if(arr[que[top]])
				value[scc] = min(value[scc],arr[que[top]]);
		}while(que[top]!=x);
	}
}
void dfs(int x){
	vis[x]=true;
	for(int i=f[x];i+1;i=e[i].next)
		if(!vis[e[i].v])
			dfs(e[i].v);
}
int main(){
	int a,b;
	scanf("%d",&n);
	scanf("%d",&p);
	init();
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&a,&b);
		arr[a] = b;
	}
	scanf("%d",&r);
	for(int i=0;i<r;i++)
	{
		scanf("%d %d",&a,&b);
		insert(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!fpn[i])
			tarjan(i);
    //for(int i=1;i<=n;i++)
    //    printf("%d ",belong[i]);
	for(int i=1;i<=n;i++)
		if(arr[i]&&!vis[i])
			dfs(i);
	for(int i=0;i<r;i++)
	    for(int j = f[i];j+1;j=e[j].next)
	        if(belong[i]!=belong[e[j].v])
		        flag[belong[e[j].v]] = true;
	for(int i=1;i<=scc;i++)
		if(flag[i]==false)
			ans+=value[i];
	for(int i=1;i<=n;i++){
		if(!vis[i])
		{
				printf("NO\n%d",i);
				return 0;
		}
	}
	printf("YES\n%d",ans);
	return 0;
}