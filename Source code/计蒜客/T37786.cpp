//T37786 jisuanke 成仙之路
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[20005],lv[20005],inq[20005];
typedef pair<int,int> P;
vector<P> G[20005];
int k,n,ans=10000,big=0,sma=1000000;
void SPFA(){
	int x=0;
    ans = arr[1];
	for(int i=sma;i<=big;i++){
		queue<P> que;
		que.push(P(1,arr[1]));
		inq[1]=1;
		while(!que.empty()){
			P p = que.front();que.pop();
			inq[p.first]=0;
			for(int j = 0;j<G[p.first].size();j++)
			{
				P o=G[p.first][j];
 				if(o.second+arr[o.first]<arr[p.first]&&i+k>=lv[o.first]){
                    int now = p.second - arr[p.first] +o.second + arr[o.first];
                    ans = min(now,ans);
                    if(!inq[o.first]){
				    	inq[o.first]=1;
					    que.push(P(o.first,now));
                    }
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> k >> n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin >> arr[i] >> lv[i] >> a;
		sma=min(sma,lv[i]);
		big=max(big,lv[i]);
		while(a--){
			cin >> b >> c;
			G[i].push_back(P(b,c));
		}
	}
	SPFA();
    cout << ans;
	return 0;
}