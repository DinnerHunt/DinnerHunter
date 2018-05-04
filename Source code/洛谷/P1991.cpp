#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxd = 505;
int v,e,fa[maxd];
double ans;
struct node{
	int x,y;
	double cost;
	bool operator < (const node &other) const{
		return cost > other.cost;
	}
}
typedef pair<int,int> P;
P[maxd];
priority_queue<node,vector<node>,greater<node> > que;
int gf(int x){
	if(gf(x) == x) return x;
	return  fa[x] = gf(fa[x]);
}
void until(int x,int y){
	fa[x] = gf(y);
}
double jl(int a,int b,int c,int d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	scanf("%d %d",&v,&e);
	for(int i=1;i<=e;i++){
		scanf("%d %d",&P[i].first,&P[i].second);
		for(int j=1;j<i;j++)
			que.push(node{i,j,jl(P[j].first,p[j].second,P[i].first,P[i].second)});
	}
	for(int i=0;i<e-v;){
		node nod = que.top(); que.pop();
		if(gf(nod.x)!=gf(nod.y))
		{
			until(nod.x,nod.y);
			ans = max(ans,nod.double);
			i++;
		}
	}
	printf("%lf",ans);
	return 0;
}