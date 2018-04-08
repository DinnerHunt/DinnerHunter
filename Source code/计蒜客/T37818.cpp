//jisuanke T37818 蒜头军运送宝藏
//DinnerHunt
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int n,m,fa[10005],arr[10005],root;
int d[maxn],p[maxn][20];
struct node{
	int from,to,cost;
}node[maxn];
typedef pair<int,int> P;
vector<P> G[maxn];
bool cmp(const node& a,const node& b){
	return a.cost > b.cost;
}
void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int gf(int x){
	if(fa[x]==x) return x;
	else fa[x] = gf(x);
}
int same(int x,int y){
	return gf(x) == gf(y);
}
void until(int x,int y){
	fa[gf[x]] = gf[y];
}
void dfs(int x){
	for(int i=0;i<G[x].size();i++)
		if(d[G[x][i]] == -1){
			d[G[x][i]] = d[x]+1;
			p[G[x][i]][0] = x;
			dfs(G[x][i]);
		}
}
int lca(int x,int y){
	
}
int main(){
	ios:sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> arr[i].from >> arr[i].to << arr[i].cost;
	sort(node+1,node+1+m,cmp);
	for(int i=1;i<=n;i++){
		node p= arr[i];
		if(!same(p.from,p.to)){
			 until(p.from,p.to);
			 G[p.from].push_back(P(p.to,p.cost));
			 arr[p.cost]++;
		}
	}
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++)
		if(!arr[i])
			root = i;
	dfs(root);
	for(int i=1;(1<<i)<=n; i++)
		for(int j=1;j<=n;j++)
			p[j][i] = p[p[j][i-1]][i-1];

	return 0;
}