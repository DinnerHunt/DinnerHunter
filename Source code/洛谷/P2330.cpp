#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 305;
int arr[maxd],fa[maxd],v,ans,e;
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
	int a,b,c;
	scanf("%d %d",&v,&e);
	init();
	for(int i=0;i<e;i++){
		scanf("%d %d %d",&a,&b,&c);
		que.push(node{a,b,c});
	}
	v--;
	for(int i=1;i<=v;)
	{
		node nod = que.top(); que.pop();
		if(gf(nod.x)!=gf(nod.y))
		{
			i++;
			until(nod.x,nod.y);
			ans=max(ans,nod.cost);
		}
	}
	printf("%d %d",v,ans);
	return 0;
}