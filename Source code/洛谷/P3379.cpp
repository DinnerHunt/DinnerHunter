#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 500005;
int d[maxd],p[maxd][30];
struct node{
    int v,next;
}e[2*maxd];
int f[maxd],eid;
int n,m,s,x,y;
void init(){
    memset(f,-1,sizeof(f));
    memset(d,-1,sizeof(d));
    eid = 0;
}
void insert(int x,int y)
{
    e[eid].v = y;
    e[eid].next = f[x];
    f[x] = eid++;
}

void dfs(int node){
    for(int i=f[node];i+1;i=e[i].next)
        if(d[e[i].v] == -1)
        {
            d[e[i].v] = d[node]+1;
            p[e[i].v][0] = node;
            dfs(e[i].v);
        }
        
}

int lca(int x,int y){
    int i,j;
    if(d[x] < d[y])
    {
        x +=y;
        y = x - y;
        x -= y;
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = p[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    
    for (j = i; j >= 0; j--) {
        if (p[x][j] != p[y][j]) {
            x = p[x][j];
            y = p[y][j];
        }
    }
    
    return p[x][0];
}

int main(){
    scanf("%d %d %d",&n,&m,&s);
    init();
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        insert(x,y);
        insert(y,x);
    }
    d[s] = 0;
    dfs(s);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            p[i][level] = p[p[i][level - 1]][level - 1]; 
        }
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}