//jisuanke T37812 布设光纤
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;


int fa[105];
int n,m,k=0;
struct edge{int u,v,cost;};
edge es[105];
bool cmp (const edge& e1,const edge& e2){
	return e1.cost < e2.cost;
}
void init(){
	for(int i=1;i<=n;i++)
		fa[i] = i;
}
int gf(int x){
	if(fa[x] == x) return fa[x];
	return  fa[x] = gf(fa[x]);
}
int same(int x,int y){
	return gf(x) == gf(y);
}
void merge(int x ,int y){
	int fax = gf(x), fay =gf(y);
	fa[fax] = fay;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
    init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> m;
			if(m!=0&&j>=i) es[++k] = (edge){i,j,m};
		}
	sort(es+1,es+k+1,cmp);
	int res=0;
	for(int i=1;i<=k;i++){
		edge e = es[i];
        cout << e.u << " " << e.v << " " << e.cost << endl;
		if(!same(e.u,e.v)){
			merge(e.u,e.v);
			res+=e.cost;
		}
	}
	cout << res;
	return 0;
}