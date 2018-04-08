//luogu P3371
//DinnerHunt
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10005;
const int INF = 2147483647;
typedef pair<int,int> P;
vector<P> G[maxn];  
int d[maxn]; 
int N,M,S;
void dijkstra(int i){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d+1,d+1+N,INF);
	que.push(P(0,i));
	d[i]=0;
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i=0;i<G[v].size();i++){
			P q = G[v][i];
			if(d[q.first]>d[v]+q.second){
				d[q.first] = d[v]+q.second;
				que.push(P(d[q.first],q.first));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> N >> M >> S;
	int a,b,c;
	for(int i=0;i<M;i++){
		cin >> a >> b >> c;
		G[a].push_back(P(b,c));
	}
	dijkstra(S);
	for(int i=1;i<=N;i++)
		cout << d[i] << " ";
	return 0;
}