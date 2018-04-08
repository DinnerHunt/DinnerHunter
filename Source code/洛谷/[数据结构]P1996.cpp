#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	queue<int> que;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		que.push(i);
	if(n==0)return 0;
	while(que.size()>1){
		while(int i=1;i<m;i++)
		{
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << " ";
		que.pop();
	}
	cout << que.front();
	return 0;
}