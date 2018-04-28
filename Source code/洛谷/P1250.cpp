#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 105;
int arr[maxd],fa[maxd],v,ans;
struct node{
	int x,y,cost;
	bool operator < (const node &other) const {
		return  cost > other.cost;
	} 
};
void init(){
	for(int i=1;i<=v;i++)
		fa[i] = i;
}
int gf(int x){
	if(fa[x] == x) return x;
	else return fa[x] = gf(fa[x]);
}
void until(int x,int y){
	fa[gf(x)] = gf(y);
}
priority_queue<node> que;
int main(){
	int a;
	scanf("%d",&v);
	init();
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++){
			scanf("%d",&a);
			if(i>j) que.push(node{i,j,a});
		}
	v--;
	while(v)
	{
		node nod = que.top(); que.pop();
		if(gf(nod.x)!=gf(nod.y))
		{
			v--;
			until(nod.x,nod.y);
			ans+=nod.cost;
		}
	}
	printf("%d",ans);
	return 0;
}