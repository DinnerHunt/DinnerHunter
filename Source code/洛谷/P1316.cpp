#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxd = 10005;
const int inf = 1e15;
struct node{
    LL to,cost;
};
typedef pair<LL,LL> P;
vector<node> G[maxd];
LL arr[maxd],d[maxd];
LL v,e,life,mid;
bool dijkstra()
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+1+v,inf);
    d[1] = 0;
    que.push(P(0,1));
    while(!que.empty())
    {
        P p = que.top(); que.pop();
        int k = p.second;
        if(d[k] < p.first) continue;
        int len = G[k].size();
        for(int i=0;i<len;i++)
        {
            node e = G[k][i];
            if(d[e.to] > d[k] + e.cost&&arr[e.to]<=mid)
            {
                d[e.to] = d[k] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if(d[v]>=life) return false;
    else return true;
}
int main(){
    LL a,b,c,l,r;
    scanf("%lld %lld %lld",&v,&e,&life);
    for(int i=1;i<=v;i++){ 
        scanf("%lld",&arr[i]);
    }
    r= inf;
    l = max(arr[1],arr[v]);
    for(int i=1;i<=e;i++)
    {
    	scanf("%lld %lld %lld",&a,&b,&c);
    	if(a==b) continue;
    	G[a].push_back(node{b,c});
    	G[b].push_back(node{a,c});
    }
    mid = inf;
    if(dijkstra()){
        while(l<=r){
    	    mid = (l+r+1) >>1;
    	    if(dijkstra()) r = mid-1;
    	    else l = mid+1;
        }
        printf("%lld",l);
    }
    else
        printf("AFK");
    return 0;
}