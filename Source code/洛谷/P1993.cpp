#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxd = 10005;
const int inf = 1e9;
struct node{
    int to,cost;
};
vector<node> G[maxd];
int dist[maxd],f[maxd];
int v,e,flag;
void spfa(int s){
    f[s] = 1;
    for(int i=0;i<G[s].size();i++)
    {
        node nod = G[s][i];
        if(dist[nod.to] > dist[s]+nod.cost)
        {
            if(f[nod.to])
            {
                flag = 1;
                return ;
            }
            dist[nod.to] = dist[s] +nod.cost;
            spfa(nod.to);
        }
    }
    f[s] = 0;
    return;
}
int main(){
    int a,b,c,d;
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        switch(a){
            case 1:
                scanf("%d",&d);
                G[c].push_back(node{b,-d});
                break;
            case 2:
                scanf("%d",&d);
                G[b].push_back(node{c,d});
                break;
            case 3:
                G[b].push_back(node{c,0});
                G[c].push_back(node{b,0});
                break;
        }
    }
    fill(dist+1,dist+1+v,inf);
    for(int i=1;i<=v;i++)
    {
        if(dist[i]==inf&&!flag)
            spfa(i);
    }
    if(flag) printf("No");
    else printf("Yes");
    return 0;
}