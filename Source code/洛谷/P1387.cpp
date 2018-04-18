//luogu P1387
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[105][105],ans;
int main(){
    int n,m,a;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a);
            if(a) dp[i][j] = min( min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            ans = max(dp[i][j],ans);
        }
    printf("%d",ans);
    return 0;
}