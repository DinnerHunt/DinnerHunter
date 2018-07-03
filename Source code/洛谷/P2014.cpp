#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 2005;
int x,n,m,head[maxd],net[maxd],arr[maxd],dp[maxd][maxd];
void init(){
    memset(net,0,sizeof(net));
    memset(head,-1,sizeof(head));
}
int dfs(int x)
{
    if(head[x] == -1) return 0;
    int sum = 0;
    for(int i=head[x];i+1;i=net[i])
    {
        int t = dfs(i);
        sum += t+1;
        for(int j=sum;j>=0;j--)
            for(int k=0;k<=t;k++)
                if(j-k-1>=0) dp[x][j] = max(dp[x][j],dp[x][j-k-1]+dp[i][k]);
        
    }
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    init();
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&arr[i]);
        net[i] = head[x];
        head[x] = i;
    }
    for(int i=1;i<=n;i++) dp[i][0] = arr[i];
    dp[0][0] = 0;
    dfs(0);
    printf("%d",dp[0][m]);
    return 0;
}