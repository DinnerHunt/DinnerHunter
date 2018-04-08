//T37828 jisuanke jisuanke
//DinnerHunt
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
int fa[maxn];
int dfn[maxn],low[maxn];
int in_stk[maxn],stk[maxn],top;	//模拟栈
int idx;			//时间戳
int belong[maxn],scc,number[maxn];		//强连通分量
int n,m,a,b,ans;
void init(){
	for(int i=1;i<=n;i++)
		fa[i] = i;
}
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x] = gf(x);
}
int same(int x,int y){
	return gf[x] == gf[y];
}
int unilt(int x,int y){
	fa[gf(x)] = gf(y);
}
void tarjan(int u){
	dfn[u] = low[u] = ++idx;
	stk[top++] = u;
	in_stk[u] = true;
	for(int i=0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(in_stk[v]){
			low[u] = min(low[u],low[v]);
		}
	}
	if(dfn[u] == low[u]){
		++scc;
		do{
			belong[stk[--top]] = scc;
			in_stk[stk[top]] = false;
			number[scc]++;
		}while(stk[top] != u);
	}
}
int main(){
    ios::sync_with_stdio(false);
	cin >> n >> m;
	init();
	for(int i=1;i<=m;i++){
		cin >> a >> b;
		if(!same(a,b))
			unilt(a,b);
		G[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!same(a,b)){
			cout << 0;
			return 0;
		}
    tarjan(1);
    for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=0;j<G[i].size();j++){
			if(belong[G[i][j]]!=belong[i])
			{
                
				flag=0;
				break;
			}
		}
		if(flag){
			ans+=number[belong[i]];
            number[belong[i]]=0;
        }
	}
	cout << ans;
	return 0;
}