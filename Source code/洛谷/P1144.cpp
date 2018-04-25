#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxd = 1000005;
const int mod = 100003;
int v,e;
int vis[maxd],cnt[maxd],d[maxd];
vector<int> G[maxd];
queue<int> que;
int main(){
	int a,b;
	scanf("%d %d",&v,&e);
	for(int i=0;i<e;i++){
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cnt[1] = 1,vis[1]=1;
	que.push(1);
	while(!que.empty())
	{
		int k = que.front();que.pop();
		for(int i=0;i<G[k].size();i++)
		{
			int s = G[k][i];
			if(!vis[s])
			{
				vis[s] = 1;
				d[s] = d[k]+1;
				que.push(s);
			}
			if(d[s] == d[k]+1){
				cnt[s] = (cnt[s]+cnt[k])%mod;
			}
		}
	}
	for(int i=1;i<=v;i++)
		printf("%d\n",cnt[i]);
	return 0;
}