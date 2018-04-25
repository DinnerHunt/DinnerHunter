#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 3000;
struct node{
	int to,cost;
};
typedef pair<int,int> P;
vector<node> G[maxd];
int v,e,start,stop,d[maxd];
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	memset(d,1,sizeof(d));
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p = que.top(); que.pop();
		int k = p.second;
		if(d[k] < p.first) continue;
		for(int i=0;i<G[k].size();i++)
		{
			node e = G[k][i];
			if(d[e.to] > d[k]+e.cost)
			{
				d[e.to] = d[k]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){	
	int a,b,c;
	scanf("%d %d %d %d",&v,&e,&start,&stop);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(node{b,c});
		G[b].push_back(node{a,c});
	}
	dijkstra(start);
	printf("%d",d[stop]);
	return 0;
}