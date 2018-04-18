#include <cstdio>
using namespace std;
const int maxd = 200005;
int dp[maxd],arr[6],sum;
int main(){
    for(int i=0;i<6;i++){
        scanf("%d",&arr[i]);
        sum+=(i+1)*arr[i];
    }
    if(sum%2)
    {
        printf("Can't be divided.");
        return 0;
    }
    dp[0] = 0;
    for(int i=0;i<6;i++)
        for(int j=0;j<=sum/2;j++)
        {
            if(dp[j] >=0 )
                dp[j] = arr[i];
            else if(j<i || dp[j-i]<0)
                dp[j] = -1;
            else 
                dp[j] = dp[j-i] -1;
        }
    if(dp[sum/2]) printf("Can be divided.");
    else printf("Can't be divided.");
    return 0;
}