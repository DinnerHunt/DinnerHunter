#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 50005;
const int maxn = 10005;
struct node{
    int v,next;
}e[maxd];
int eid,f[maxn];
void init(){
    memset(f,-1,sizeof(f));
    eid = 0;
}
void insert(int x,int y)
{
    e[eid].v= y;
    e[eid].next = f[x];
    f[x] = eid++;
}
int fpn[maxn],low[maxn],belong[maxn],que[maxn],size[maxn];
int ka[maxn];
int ssc,top,number,ans;
bool inq[maxn],vis[maxn],flag[maxn],che[maxn];
int n,m;
void tarjan(int x){
    fpn[x] = low[x] = ++number;
    que[top++] = x;
    inq[x] = true;
    for(int i = f[x];i+1;i=e[i].next)
    {
        int v = e[i].v;
        if(!fpn[v])
        {
            tarjan(v);
            low[x] = min(low[v],low[x]); 
        }
        else if(inq[v])
            low[x] = min(low[x],fpn[v]);
    }
    if(fpn[x] == low[x])
    {
        ssc++;
        do{
            belong[que[--top]] = ssc;
            inq[que[top]] = false;
            size[ssc]++;
        }while(que[top] != x);
    }
}
void dfs(int x)
{
    vis[x] = true;
    che[belong[x]] = true;
    for(int i=f[x];i+1;i=e[i].next)
        if(!vis[e[i].v])
        {
            if(!che[belong[e[i].v]]) ka[belong[e[i].v]]++;
            dfs(e[i].v);
        }
}
int main(){
    int a,b;
    scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        insert(a,b);
    }
    for(int i=1;i<=n;i++)
        if(!fpn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        if(!flag[belong[i]]){
            flag[belong[i]] = true;
            memset(vis,false,sizeof(vis));
            memset(che,false,sizeof(che));
            dfs(i);
        }
    for(int i=1;i<=ssc;i++)
        if(ka[i]==ssc-1){
            ans+=size[i];
        }
    printf("%d",ans);

    return 0;
}