//UVa 12118
//检查员的难题 Inspector's Dilemma
//DinnerHunt
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e3+5;
int flag[maxn];
vector<int> G[maxn],vet;
int V,T,K,spot;
void init(){
	memset(flag,0,sizeof(flag));
	memset(degree,0,sizeof(degree));
	for(int i=1;i<=K;i++)
		G[i].clear();
	spot=0;
}
int Euler(){
	int s = 0;
	for(int i=0;i<vet.size();i++)
		if(G[vet[i]].size()%2)
			s++;
	vet.clear();
	return max(s,2);
}
void bfs(int k){
	queue<int> que;
	flag[k]=1;
	que.push(k);
	vet.push_back(k);
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i=0;i<G[x].size();i++)
			if(!flag[G[x][i]])
			{
				que.push(G[x][i]);
				vet.push_back(G[x][i]);
				flag[G[x][i]]=1;
			}
	}
	spot += Euler();
}
int main(){
	int count=1;
	while(scanf("%d %d %d",&V,&K,&T)==3&&V&&K&&T){
		init();
		for(int i=0;i<K;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(int i=1;i<=V;i++)
			if(!G[i].empty()&&!flag[i])
				bfs(i);
		printf("Case %d: %d\n",count++,(K+max(spot/2-1,0))*T);
	}
	return 0;
}
