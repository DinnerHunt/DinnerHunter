#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> G[1005];
int arr[1005],flag[1005],n,m,a,b,ans;
void bfs(){
	queue<int> que;
	que.push(1);
	while(!que.empty())
	{
		int k=que.front();
		flag[k]=1;
		for(int i=0;i<G[k].size();i++){
			if(!flag[G[k][i]])
				que.push(G[k][i]);
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m ;
    for(int i=1;i<=m;i++){
    	cin >> a >> b;
    	G[a].push_back(b);
    	G[b].push_back(a);
    	arr[a]++;
    }
    for(int i=1;i<=n;i++)
    	if(arr[i]%2) ans=1;
    bfs();
    for(int i=1;i<=n;i++)
    	if(!flag[i]) ans=1;
    if(ans) cout << "0";
    else cout << "1";
    return 0;
}