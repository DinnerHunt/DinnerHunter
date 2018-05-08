#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int maxd = 10005;
const int inf = 1e9;
struct node{
	int v,next;
}e[maxd];
int f[2*maxd],arr[2*maxd],eid;
int belong[2*maxd],fpn[2*maxd],low[2*maxd],value[2*maxd];
bool inq[2*maxd],flag[2*maxd];
int n,p,r,scc,idx,ans;
void init(){
	memset(f,-1,sizeof(f));
	memset(flag,false,sizeof(flag));
	memset(inq,false,sizeof(inq));
	eid = 0;
}
void insert(int x,int y){
    e[eid].v= y;
    e[eid].next = f[x];
    f[x] = eid++;
}
queue<int> que;
void tarjan(int x){
	low[x] = fpn[x] = ++idx;
	que.push(x);
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
		int k;
		value[scc] = inf;
		do{
			k = que.front();
			if(arr[k])
				value[scc] = min(value[scc],arr[k]);
			que.pop();
			inq[k] = false;
			belong[k] = scc;
		}while(k!=x);
	}
}

int main(){
	int a,b;
	scanf("%d",&n);
	scanf("%d",&p);
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
	for(int i=1;i<=a;i++)
		if(!fpn[i])
			tarjan(j);
	for(int i=1;i<=r;i++)
		flag[belong[e[i].v]] = true;
	set<int> s;
	for(int i=1;i<=scc;i++)
		if(flag[i]==false)
			if(value[i]==inf) 
				s.insert(i);
			else
				ans+=value[i];
	if(!s.empty)
		for(int i=1;i<=n;i++){
			if(s.count(belong[i]))
			{
				printf("NO\n%d",i);
				return 0;
			}
		}
	else
		printf("YES\n%d",ans);
	return 0;
}