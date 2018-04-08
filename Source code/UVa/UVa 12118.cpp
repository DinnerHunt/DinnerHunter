#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
int v,e,t,cnt;
bool vis[maxn];
vector<int> g[maxn];
bool read(){
    cin>>v>>e>>t;
    if(!v&&!e&&!t) return false;
    for(int i=0;i<maxn;++i)
        g[i].clear();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<e;++i){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return true;
}
void dfs(int cur){
    if(vis[cur]) return;
    vis[cur]=true;
    cnt+=(int)g[cur].size()&1;//统计度数为奇数的点。
    for(int i=0;i<g[cur].size();++i)
        dfs(g[cur][i]);//DFS求连通。
    return;
}
int solve(){
    int ans=0;
    for(int i=1;i<=v;++i){
        if(!vis[i]&&!g[i].empty()){
            cnt=0;
            dfs(i);
            ans+=max(cnt,2);//每条道路至少需要2个端点，防止出现回路出错。
        }
    }
    return t*(max(ans/2-1,0)+e);//之前求得的和减去初始值任选可以减少的一次，再加上必经的e条道路。
}
int main(){
    ios::sync_with_stdio(false);
    int k=0;
    while(read())
        cout<<"Case "<<++k<<": "<<solve()<<endl;
    return 0;
}