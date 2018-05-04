#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 30005;
struct node{
    int to,cost;
};
vector<node> G[maxd];
int inq[maxd],dist[maxd];
int v,e,s;
void SPFA(int s){
    queue<int> que;
    fill(dist,dist+2,1e9); 
    inq[s] = 1;
    dist[s] = 0;
    que.push(s);
    while(!que.empty())
    {
        int k = que.front();que.pop();
        inq[k] = 0;
        for(int i=0;i<G[k].size();i++)
        {
            node nod = G[k][i];
            if(dist[nod.to] > dist[k] + nod.cost)
            {
                dist[nod.to]  = dist[k]+nod.cost;
                if(!inq[nod.to])
                {
                    que.push(nod.to);
                    inq[nod.to] =1;
                }
            }
        }
    }
}
int main(){
    int a,b,c;
    scanf("%d %d",&v,&e);
    s = v+1;
    for(int i=0;i<=v;i++) G[s].push_back(node{i,0});
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[b].push_back(node{a-1,-c});
    }
    for(int i=1;i<=v;i++)
    {
        G[i].push_back(node{i-1,0});
        G[i-1].push_back(node{i,1});
    }
    SPFA(s);
    int minx = 1e9;
    for(int i=0;i<=v;i++) minx = min(minx,dist[i]);
    printf("%d",dist[v] - minx);
    return 0;
}