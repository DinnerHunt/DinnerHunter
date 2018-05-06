#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxd = 105;
const int inf = 1e9;
struct node{
	int to,cost;
};
vector<node> G[maxd];
int v,e,vis[maxd],dist[maxd],flag;

void spfa(int k){
	vis[k] = 1;
	for(int i=0;i<G[k].size();i++)
	{
		node nod = G[k][i];
		if(dist[nod.to] > dist[k]+nod.cost)
		{
			if(vis[nod.to])
			{
				flag =1;
				return;
			}
			dist[nod.to] = dist[k]+nod.cost;
			spfa(nod.to);
		}
	}
	vis[k] = 0;
}
void init(){
	for(int i=0;i<=v;i++)
		G[i].clear();
	memset(vis,0,sizeof(vis));
	fill(dist,dist+v+1,inf);
	flag = 0;
}
int main(){
	int n,a,b,c,s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&v,&e);
		init();
		for(int i=0;i<e;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			G[a-1].push_back(node{b,c});
			G[b].push_back(node{a-1,-c});
		}
		for(int i=0;i<=v;i++){
			if(dist[i] == inf &&!flag)
				spfa(i);
		}
		if(flag) printf("false\n");
		else printf("true\n");
	}
	return 0;
}