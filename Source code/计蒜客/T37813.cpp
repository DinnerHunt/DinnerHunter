//jisuanke T37813 连线问题
//DinnerHunt
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
typedef pair<double,int> Q;
P arr[105];
int n,used[105];
double G[105][105];
double jl(int a,int b){
	double k = ((arr[a].first-arr[b].first)*(arr[a].first-arr[b].first)*1.0+(arr[a].second-arr[b].second)*(arr[a].second-arr[b].second)*1.0)
	return sqrt(k);
}
double prim(){
	priority_queue<Q,vector<Q>,greater<Q> >que; 
	que.push(Q(0,1));
	double ans=0;
	while(que.empty()){
		Q q = que.top();que.pop();
		int k = que.second;
		ans += q.first;
		if(used[k])continue;
		used[k]=1;
		for(int i=1;i<=n;i++)
			if(G[q][i]!=0&&!used[i])
				que.push(Q(G[q][i],i));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i].first >> arr[i].second;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			G[i][j] = G[j][i] = jl(i,j);
	cout << prim();
	return 0;
}