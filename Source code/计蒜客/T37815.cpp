//jisuanke T37815 高速公路
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000;
int n,m,fa[105],ans=INF;
struct edge{int u,v,cost;};
edge arr[10005];
bool cmp(edge a,edge b){
	return a.cost < b.cost;
}
void init(){
	for(int i=1;i<=n;i++)
		fa[i] = i;
}
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x] = gf(fa[x]);
}
int same(int x,int y){
	return gf(x) == gf(y);
}
int unitl(int x,int y){
	if(!same(x,y))
		fa[gf(x)] = gf(y);
}
void Kruskal(int k){
	int mx=0,mi=INF,number=0;
	init();
	for(int i=k;i<=m;i++){
		if(!same(arr[i].u,arr[i].v)){
			unitl(arr[i].u,arr[i].v);
			number++;
			mi = min(mi,arr[i].cost);
			mx = max(mx,arr[i].cost);
		}
	}
	if(number==n-1)
	ans = min(ans,mx-mi);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> arr[i].u >> arr[i].v >> arr[i].cost;
	sort(arr+1,arr+m+1,cmp);
	for(int i=1;i<=m;i++)
		Kruskal(i);
    if(ans!=INF)
	cout << ans;
    else 
        cout << -1;
	return 0;
}