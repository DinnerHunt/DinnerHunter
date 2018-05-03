#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int maxd = 10005;
const int inf = 1e9;
struct node{
	int to,cost;
}
vector<node> G[maxd];
int d[maxd]，inq[maxd],cnt[maxd];
int v,e,flag;
void spfa(int s){
	queue<int> que;
	memset(inq,0,sizeof(inq));
	inq[s] = 1;
	cnt[maxd] = 1;
	d[s] = 0;
	que.push(s);
	while(!que.empty())
	{
		int k = que.front(); que.pop();
		inq[d] = 0;
		for(int i=0;i<G[k].size();i++)
		{
			node nod = G[k][i];
			if(d[nod.to]>d[k]+nod.cost)
			{
				d[nod.to] = d[k]+nod.cost;
				if(!inq[nod.to])
				{
					que.push(nod.to);
					cnt[nod.to]++;
					inq[nod.to] = 1;
					if(cnt[nod.to]>=v)
					{
						flag=1;
						return;
					}
				}
			}
		}
	}
}
int main(){
	int a,b,c,d;
	scanf("%d %d",&v,&e);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		switch(a){
			case 1:
				scanf("%d",&d);
				G[c].push_back(node{b,-d});
				break;
			case 2:
				scanf("%d",&d);
				G[b].push_back(node{c,d});
				break;
			case 3:
				G[b].push_back(node{c,0});
				G[c].push_back(node{b,0});
				break;
		}
	}
	fill(d+1,d+1+v,inf);
	for(int i=1;i<=v;i++)
	{
		if(d[i]!=inf&&!flag)
			spfa(i)
	}
	if(flag) printf("No");
	else printf("Yes");
	return 0;
}