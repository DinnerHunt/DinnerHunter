#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 20005;
int dp[maxd],w[maxd];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<m;i++)
        for(int j=n;j>=w[i];j--)
            dp[j] = max(dp[j-w[i]]+w[i],dp[j]);
    printf("%d",n-dp[n]);
    return 0;
}