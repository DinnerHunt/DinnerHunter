//jisuanke T37821 威虎山上的分配
//DinnerHunt
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> G[10005];
typedef pair<int,int> P;
int n,m,a,b,arr[100005];
int topu(){
	int ans=0,number=0; 
	queue<P> que;
	for(int i=1;i<=n;i++)
		if(!arr[i]){
			que.push(P(i,100));
        }
	while(!que.empty())
	{
		P p = que.front();
		que.pop();
		number++;
		ans+=p.second;
		int k = p.first;
		for(int i=0;i<G[k].size();i++){
			arr[G[k][i]]--;
			if(!arr[G[k][i]])
				que.push(P(G[k][i],p.second+1));
		}
	}
	if(number==n) return ans;
	return 0;
}
int main(){
	cin >>n >> m;
	for(int i=0;i<m;i++)
	{
		cin >> a >>b;
		G[b].push_back(a);
		arr[a]++;
	}
	int ans = topu();
	if(!ans) cout << "Unhappy!";
	else cout << ans;
	return 0;
}