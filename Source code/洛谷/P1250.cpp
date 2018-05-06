#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxd = 1005;
const int inf = 1e9;
struct node{
    int to,cost;
};
vector<node> G[maxd];
int v,ml,md,dist[maxd],flag,cnt[maxd];
bool inq[maxd];
void spfa(){
    queue<int> que;
    fill(dist+1,dist+1+v,inf);
    dist[1] = 0;
    inq[1] = true;
    cnt[1] = 1;
    que.push(1);
    while(!que.empty())
    {
        int k = que.front();
        que.pop();
        inq[k] = false;
        for(int i=0;i<G[k].size();i++)
        {
            node nod = G[k][i];
            if(dist[nod.to] > dist[k]+nod.cost)
            {
                dist[nod.to] = dist[k]+ nod.cost;
                if(!inq[k])
                {
                    inq[k] = true;
                    que.push(k);
                    if(cnt[k]++ == v)
                    {
                        flag = -1;
                        return ;
                    }
                }
            }
        }

    }
    if(dist[v] == inf) flag = -2;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&v,&ml,&md);
    for(int i=2;i<=v;i++) G[i].push_back(node{i-1,0});
    for(int i=0;i<ml;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(node{b,c});
    }
    for(int i=0;i<md;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[b].push_back(node{a,-c});
    }
    spfa();
    if(flag) printf("%d",flag);
    else printf("%d",dist[v]);
    return 0;
}