#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxd = 200;
int d[maxd];
typedef pair<int,int> P;
struct node{
    int cost,to;
};
vector<node> G[maxd];
int v,start,stop;
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    memset(d,1,sizeof(d));
    d[s] = 0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p = que.top();que.pop();
        int k = p.second;
        if(d[k] < p.first) continue;
        for(int i=0;i<G[k].size();i++)
        {
            node e = G[k][i];
            if(d[e.to]>d[k]+e.cost)
            {
                d[e.to] = d[k]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(){
    int n,a;
    scanf("%d %d %d",&v,&start,&stop);
    for(int i=1;i<=v;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a);
            if(j) G[i].push_back(node{1,a});
            else G[i].push_back(node{0,a});
        }
    }
    dijkstra(start);
    if(d[stop] >16843000) printf("-1");
    else printf("%d",d[stop]);
    return 0;
}