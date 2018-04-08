//T37817 jisuanke 节点的最近公共祖先
//DinnerHunt
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10005;
int n,m,a,b;
vector<int> G[maxn];
int d[maxn],p[maxn][20];
void init(){
	for(int i=1;(1<<i) <=n; i++)
		for(int j=1;j<=n;j++)
			p[j][i] = p[p[j][i-1]][i-1];
}
int lca(int x,int y){
	int i,j;
	if(d[x] < d[y])
		swap(x,y);
	for(i=0;(1<<i)<=d[x];i++);i--;
	for(j=i;j>=0;j--)
		if(d[x]-(1<<j) >= d[y])
			x=p[x][j];
	if(x==y) return x;
	for(j=i;j>=0;j--)
	{
		if(p[x][j]!=p[y][j])
		{
			x = p[x][j];
			y = p[y][j];
		}
	}
	return p[x][0];
}
void dfs(int node){
	for(int i=0;i<G[node].size();i++){
		if(d[G[node][i]]==-1){
			d[G[node][i]] = d[node] + 1;
			p[G[node][i]][0] = node;
			dfs(G[node][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> a >> b;
		G[a].push_back(b);
	}
	memset(d,-1,sizeof(d));
    d[1]=1;
	dfs(1);
	init();
	cin >> m;
	for(int i=0;i<m;i++){
		cin  >> a >> b;
		if(i) cout << endl;
		cout << lca(a,b);
	}
	return 0;
}