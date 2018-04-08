//P1330 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int n,m,arr[10005],a,b,flag[10005],ans=0;
vector<int> G[10005];
bool bfs(int x){
	queue<int> que;
	que.push(x);
	flag[x]=1;
	int sum=1,blk=1;
	while(que.size())
	{
		int x =que.front();
		now = flag[x];
        que.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int y = G[x][i];
            if(flag[y]==-1){
				if(now) blk++;
				sum++;
				flag[y]=now;
				que.push(y);
			}
			else if(flag[y]!=now)
				return false;
		}
	}
	ans+=min(blk,sum-blk);
	return true;
} 
int main(){
	ios::sync_with_stdio(false);
	cin  >> n >> m;
	for(int i=1;i<=m;i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
        G[b].push_back(a);
	}
	memset(flag,-1,sizeof(flag));
	for(int i=1;i<=n;i++){
		if(flag[i]==-1)
			if(!bfs(i))
			{
				cout << "Impossible";
				return 0;
			}
	}
	cout << ans;
	return 0;
}