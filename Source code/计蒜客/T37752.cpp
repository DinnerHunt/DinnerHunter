#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 10005;
int dp[maxd],w[1005],v[1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d %d",&w[i],&v[i]);
    for(int i=0;i<n;i++)
        for(int j=w[i];j<=m;j++)
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    printf("%d",dp[m]);
    return 0;
}