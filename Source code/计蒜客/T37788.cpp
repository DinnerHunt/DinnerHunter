//t37788 jisuanke 蒜头君的银行卡
//DinnerHunt
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0;
typedef pair<int,int> P;
vector<P> G[10000];
int n,m,k,a,b,c;
int d[10000],arr[10000],inq[10000],flag;
void SPFA(int x){
	d[x]=0;
	queue<int> que;
	arr[x]++;
	inq[x]=1;
	que.push(x);
	while(!que.empty()&&!flag){
		int u = que.front();
		que.pop();
		inq[u] = 0;
		for(int i = 0;i<G[u].size();i++){
			int v = G[u][i].first;
			if(d[u]+G[u][i].second>d[v]){
				d[v] = d[u]+G[u][i].second;
				if(!inq[v])
				{
					que.push(v);
					inq[v] = 1;
					arr[v]++;
					if(arr[v]>n){
						flag=1;
						break;
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> k;
		switch(k){
			case 1:
				cin >> a >> b >> c;
				G[a].push_back(P(b,c));
				break;
			case 2:
				cin >> a >> b >> c;
				G[b].push_back(P(a,-c));
				break;
			case 3:
				cin >> a >> b;
				G[b].push_back(P(a,0));
				G[a].push_back(P(b,0));
				break;
		}
	}
	fill(d+1,d+1+m,INF);
	for(int i=1;i<=n;i++){
		if(d[i]==INF&&!flag)
            SPFA(i);
	}
	if(flag)cout << "No";
	else cout << "Yes";
	return 0;
}