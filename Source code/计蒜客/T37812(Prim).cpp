//jisuanke T37812 布设光纤
//DinnerHunt
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000;
typedef pair<int,int> P;
int n,G[105][105],used[105];
int prim(){
	priority_queue<P,vector<P>,greater<P> >que;
	memset(used,0,sizeof(used));
	que.push(P(0,1));
	int res = 0;
	while(!que.empty()){
		P p = que.top();que.pop();
		int k = p.second;
        if(used[k]) continue;
		used[k] = 1;
		res+=p.first;
		for(int i=1;i<=n;i++){
			if(G[k][i]!=0&&!used[i])
				que.push(P(G[k][i],i));
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> G[i][j];
	cout << prim();
	return 0;
}