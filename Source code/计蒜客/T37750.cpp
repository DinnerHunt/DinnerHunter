#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1005],w[105],v[105];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d",&w[i],&v[i]);
    for(int i=0;i<m;i++)
        for(int j=n;j>=w[i];j--)
            dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
    
    printf("%d",dp[n]);
    return 0;
}