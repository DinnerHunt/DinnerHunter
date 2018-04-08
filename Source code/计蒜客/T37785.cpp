//jisuanke 图论 闯关游戏
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> G[105];
const int INF = 10000000;
typedef pair<int,int> P;
int arr[105],d[105],inq[105],number[105],n;
void SPFA(int x){
	memset(d,-1,sizeof(d));
	d[x] = 100;
	inq[x] = 1;
	queue<P> que;
	que.push(P(x,100));
	while(!que.empty()){
		P p= que.front();
		que.pop();
		int a=p.first,b=p.second;
		inq[a] = 1;
		for(int i=0;i<G[a].size();i++)
		{
			int c = G[a][i];
			if(b+arr[c]>0){
				d[c] = b+c;
				number[c]++;
				if(number[c]<n&&!inq[c]){
					que.push(P(c,b+c));
					inq[c] = 1;
				}
			}
		}
	}
}
int main(){
	int a,b,c;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b >> c;
		arr[i] = a;
		G[b].push_back(c);
	}	
	SPFA(1);
    if(d[n]>0) cout << "Yes";
    else cout << "No";
	return 0;
}