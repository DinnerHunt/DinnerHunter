#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 205;
int dp[maxd][maxd],a[maxd],b[maxd];
int main(){
    int n,m,t,ans=0;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(int i=0;i<n;i++)
        for(int j = m ; j>= b[i] ; j--)
            for(int k=t ; k>= a[i] ; k--){
                dp[j][k] = max(dp[j][k],dp[j-b[i]][k-a[i]]+1);
                ans = max(dp[j][k],ans);
            }
    printf("%d",ans);
    return 0;
}