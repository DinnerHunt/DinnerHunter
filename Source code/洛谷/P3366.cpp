//luogu P3366
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int to,from,cost;
}arr[200005];
bool cmp(const node &a,const node &b){
	return a.cost < b.cost;
}
int n,m,ans;
int fa[50005];
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
void until(int x,int y){
	fa[gf(x)] = gf(y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
    init();
	for(int i=1;i<=m;i++)
		cin >> arr[i].from >> arr[i].to >> arr[i].cost;
	sort(arr+1,arr+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(!same(arr[i].from,arr[i].to)){
			ans+=arr[i].cost;
			until(arr[i].from,arr[i].to);
		}
	}
	cout << ans;
	return 0;
}