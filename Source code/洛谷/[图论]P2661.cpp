//luogu P2661
//DinnerHunt 
#include <iostream>
#include <algorithm>
using namespace std;
const int max_a = 200005;
const int INF = 2147483647;
int n,num,t[max_a],f[max_a],d[max_a],ans = INF;

int dfs(int x,int dep){
	if(f[x]==num) return dep - d[x];
	if(f[x]) return INF;
	f[x] = num;
	d[x] = dep;
	return dfs(t[x],dep+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> t[i];
	for(int i=1;i<=n;i++) if(!f[i]) ans = min(ans,dfs(i,++num)); 
    cout << ans;
	return 0;
}