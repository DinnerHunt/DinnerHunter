#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxd = 200005;
typedef long long LL;
vector<int> G[maxd];
LL ans,maxn,arr[maxd];
int main(){
    int a,b,v;
    scanf("%d",&v);
    for(int i=1;i<v;i++){
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=v;i++) scanf("%lld",&arr[i]);
    for(int k=1;k<=v;k++){
        LL sum = 0,mx=0;
        for(int i=0;i<G[k].size();i++){
            ans += sum*arr[G[k][i]];
            maxn = max(mx*arr[G[k][i]],maxn);
            ans%=10007;
            sum+=arr[G[k][i]];
            mx = max(arr[G[k][i]],mx);
        }
    }
    printf("%d %d",maxn,(ans*2)%10007);
    return 0;
}