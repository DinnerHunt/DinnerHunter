//jisuanke T37814 穿越雷区
//DinnerHunt
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000;
typedef pair<int,int> P;
vector<P> G[30005];
int n,m,a,b,c,used[30005];
int prim(){
	priority_queue<P,vector<P>,greater<P> > que;
	int ans=0;
	que.push(P(0,1));
	while(!que.empty()){
		P p= que.top();que.pop();
		int k = p.second;
		if(used[k]) continue;
		used[k] = 1;
		ans+=p.first;
		for(int i=0;i<G[k].size();i++){
			P q = G[k][i];
			if(q.second!=0&&used[q.first])
				que.push(P(q.second,q.first));
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	fill(G+1,G+n+1,INF);
	for(int i=1;i<=n;i++){
		cin >> a >> b >> c;
		G[a].push(P(b,c));
	}
	cout << prim();
	return 0;
}