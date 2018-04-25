#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int maxd = 10005;
const int inf = 1000000050;
struct node{
	int cost,to;
};
struct P{
	int from,cost,life;
	bool operator < (const P &other) const {
		return life > other.life;
	}
}
vector<node> G[maxd];
int v,e,life_max,arr[maxd],d[maxd];
void dijkstra(){
	priority_queue<P> que;
	fill(d+1,d+1+v,inf);
	d[1] = arr[1];
	que.push(P{1,d[i],0});
	while(!que.empty()){
		P p = que.top(); que.pop();
		int k = q.from;
		if(d[k] < p.cost) continue;
		for(int i=0;i<G[k].size();i++)
		{
			node e = G[k][i];
			if(e.cost+p.life <= life_max)
			{
				d[e.to] = max(p.cost,arr[e.to]);
				que.push(P(e.to,d[e.to],e.cost+p.life));
			}
		}

	}
}

int main(){
	int a,b,c;
	scanf("%d %d %d",&v,&e,&life_max);
	for(int i=1;i<=v;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=e;i++){
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(node{b,c});
		G[b].push_back(node{a,c});
	}
	dijkstra();
	printf("%d",d[v]);
	return 0;
}