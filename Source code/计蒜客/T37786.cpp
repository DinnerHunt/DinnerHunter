#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxd = 20005;
int s,v;
int d[maxd],lv[maxd];
struct node{
	int to,cost;
};
vector<node> G[maxd];

void spfa(){
	for(int i=lv[1]-s;;)
}
int main(){
	int a,b,c;
	scanf("%d %d",&s,&v);
	for(int i=1;i<=v;i++)
	{
		scanf("%d %d %d",&b,&lv[i],&a);
		G[0].push(node{i,b});
		for(int i=0;i<a;i++)
		{
			scanf("%d %d",&b,&c);
			G[i].push(node{b,c});
		}
	}
	spfa();
	return 0;
}