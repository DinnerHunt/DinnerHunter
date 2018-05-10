#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxd = 1000005;
const int maxn = 100005;
vector<int> R[maxd],C[maxd];
struct edge{
	int v,next;
}e[maxn*50];
int f[maxn],eid,d[maxd],ans;
void init(){
	memset(f,-1,sizeof(f));
	eid = 0;
}
void insert(int x,int y){
	e[eid].v = y;
	e[eid].next = f[x];
	f[x] = eid++;
}
int fpn[maxn],low[maxn],belong[maxn],ssc,number,size[maxn];
int que[maxn],top;
int inq[maxn];
void tarjan(int x){
    fpn[x] = low[x] = ++number;
    que[top++] = x;
    inq[x] = true;
    for(int i=f[i];i+1;e[i].next)
    {
        int v = e[i].v;
        if(!fpn[v]){
            tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(inq(v))
            low[x] = min(low[x],fpn[v]);
    }
    
    if(fpn[x] == low[x])
    {
        ssc++;
        do{
        	size[scc]++;
            belong[que[--top]] = ssc;
            inq[que[top]] = false;
        }while(que[top]!=x);
    }
}
void dfs(int x){
	if(d[x]) return d[x];
	d[x] = size[belong[x]];
	for(int i = f[x];i+1;i=e[i].next)
		if(belong[x]!=belong[e[i].v])
			d[x] = max(d[x],dfs(e[i].v)+size[belong[e[i].v]]);
		else
			d[x] = max(d[x],dfs(e[i].v));
}
struct node{
	int x,y,z;
}arr[maxn];
int n,r,c;
int main(){
	int a,b,c;
	scanf("%d %d %d",&n,&r,&c);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
		R[arr[i].x].push_back(i);
		C[arr[i].y].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		switch(arr[i].z)
		{
			case 1:
				for(int j=0;j<R[arr[i].x].size();j++)
				    if(i!=R[arr[i].x][j])
					    insert(i,R[arr[i].x][j]);
			break;
			case 2:
				for(int j=0;j<C[arr[i].y].size();j++)
				    if(i!=C[arr[i].y][j])
				    	insert(i,C[arr[i].y][j]);
			break;
			case 3:
				for(int j=arr[i].x-1;j<=arr[i].x+1;j++)
					if(j>0&&j<=r)
						for(int k=0;k<R[j].size();k++)
							if(arr[R[j][k]].y>=arr[i].y-1&&arr[R[j][k]].y<=arr[i].y+1)
							    if(i!=R[j][k])
								    insert(i,R[j][k]);
			break;
		}
	}
	for(int i=1;i<=n;i++)
	    if(!fpn[i])
	    	tarjan(i);

	for(int i=1;i<=n;i++){
		if(!d[i])
			dfs(i);
		ans = max(d[i],ans);
	}
	
	return 0;
}	