//P1629 邮递员送信
//DinnerHunt
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int maxd = 1005;
typedef pair<int,int> P; 
int G[2][maxd][maxd];
int d1[maxd],d2[maxd];
int v,e,sum;
void dijkstra()
{
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,1));
	d1[1] =d2[1]= 0;
	while(!que.empty())
	{
		P p = que.top();que.pop();
		int k = p.second;
		if(d1[k] < p.first) continue;
		for(int i=1;i<=v;i++)
		{
			if(d1[k]+G[0][k][i] < d1[i])
			{
				d1[i] = d1[k] + G[0][k][i];
				que.push(P(d1[i],i));
			}
		}
	}
	que.push(P(0,1));
	while(!que.empty())
	{
		P p = que.top();que.pop();
		int k = p.second;
		if(d2[k] < p.first) continue;
		for(int i=1;i<=v;i++)
		{
			if(d2[k]+G[1][k][i] < d2[i])
			{
				d2[i] = d2[k] + G[1][k][i];
				que.push(P(d2[i],i));
			}
		}
	}
}
int main(){
	int a,b,c;
	scanf("%d %d",&v,&e);
	memset(G,1,sizeof(G));
	memset(d1,1,sizeof(d1));
    memset(d2,1,sizeof(d2));
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[0][a][b] = min(G[0][a][b],c);
		G[1][b][a] = min(G[1][b][a],c);
	}
	dijkstra();
	for(int i=2;i<=v;i++){
        sum+=d1[i];
        sum+=d2[i];
	}
	printf("%d",sum);
	return 0;
}