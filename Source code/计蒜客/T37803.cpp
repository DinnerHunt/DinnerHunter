#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e4+5;
vector<int> G[maxn];
int arr[maxn],n,m;
void solve(int u){
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]){
            int k = G[u][i];
			G[u][i]=0;
			solve(k);
		}
	}
	printf("%d\n",u);
}
int main(){
	int a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	solve(1);
	return 0;
}