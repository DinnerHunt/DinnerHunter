#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxd = 50005;
typedef pair<int,int> P;
struct node{
	int to,cost;
};
vector <node> G[maxd];
int w[maxd],d[maxd];
long long ans;
bool flag[maxd];
void dijkstra(){
	priority_queue<P,vector<P>,greater<P> > que;
    memset(d,1,sizeof(d));
	que.push(P(0,1));
	d[1] = 0;
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v= p.second;
        flag[v]=true;
		if(d[v] < p.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
			node e = G[v][i];
			if(d[v]+e.cost<d[e.to]){
				d[e.to] = d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){
	int a,b,c,n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(node{b,c});
		G[b].push_back(node{a,c});
	}
	dijkstra();
	for(int i=2;i<=n;i++){
		if(!flag[i]){
			printf("-1");
			return 0;
		}
		ans += d[i]*w[i];
	}
	printf("%lld",ans);
	return 0;
}