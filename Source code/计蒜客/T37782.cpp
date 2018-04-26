#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxd = 205;
struct pos{
	int x,y;
}arr[maxd];
struct node{
	double cost;
	int to;
};
double dis(int a,int b,int c,int d){
	return  sqrt((a-c)*(a-c)+(b-c)*(b-c));
}
vector<node> G[maxd];
typedef pair<double,int> P;
double d[maxd],d2[maxd];
int edge[maxd],fx,fy;
void dijkstra(){
	priority_queue<P,vector<P>,greate<P> > que;
	que.push(P(0,1));
	d[1]=0;
	while(!que.empty())
	{
		P p = que.top(); que.pop();
		int k = p.second;
		if(d[k]<p.first) continue;
		for(int i=0;i<G[k].size();i++){
			node e = G[k][i];
			if(d[e.to]>d[k]+e.cost){
				d[e.to] = d[k] + e.cost;
				edge[e.to] = k;				//最短上一节点为k
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
void dijkstra2(){
	priority_queue<P,vector<P>,greate<P> >que;
	que.push(P(0,1));
	d[1]=0;
	while(!que.empty())
	{
		P p = que.top();que.pop();
		int k = p.second;
		if(d[k] < p.first) continue;
		for(int i=0;i<G[k].size();i++)
		{
			node e = G[k][i];
			if((k==fx&&e.to==fy)||(e.to==fx&&k==fy)) continue;
			if(d[e.to]>d[k]+e.cost){
				d[e.to] = d[k] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){
	int v,e,a,b;
	scanf("%d %d",&v,&e);
	for(int i=1;i<=b;i++)
		scanf("%d %d",&arr[i].x,&arr[i].y);
	for(int i=1;i<=e;i++){
		scanf("%d %d",&a,&b);
		vector[a].push_back(node{dis(arr[a].x,arr[a].y,arr[b].x,arr[b].y),b});
		vector[b].push_back(node{dis(arr[a].x,arr[a].y,arr[b].x,arr[b].y),a});
	}
	memset(d,1,sizeof(d));
	dijkstra();
	memset(d2,1,sizeof(d));
	for(int i=v;i!=1;i=edge[i]){
		fx = i, fy = edge[i];
		dijkstra2();
	}
	printf("%d",d2[n]);
	return 0;
}