#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 85;
__int128 dp[maxd][maxd];
__int128 ans[85];
__int128 sum;
int arr[maxd][maxd];
void print(){
    int a = sum%10;
    sum/=10;
    if(sum!=0)
        print();
    printf("%d",a);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    ans[0]=1;
    for(int i=1;i<85;i++)
        ans[i] = ans[i-1]*2;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    for(int s=0;s<n;s++)
    {
        for(int i=0;i<m;i++){
            dp[i][i] = ans[m]*arr[s][i];
        }
        for(int len=1;len<m;len++)
            for(int i=0;i+len<m;i++){
                dp[i][i+len] = max(dp[i+1][i+len]+arr[s][i]*ans[m-len],dp[i][i+len-1]+arr[s][i+len]*ans[m-len]);
            }
        sum += dp[0][m-1];
    }
    print();
    return 0;
}