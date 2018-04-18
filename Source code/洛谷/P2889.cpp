//P2889 luogu
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 1002005;
int dp[maxd],n,m,r;
struct node{
    int x,y,z;
    bool operator < (const node &other) const{
        return  y< other.y;
    }
}arr[1005];
int main(){
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
    sort(arr,arr+m);
    int k=0;
    for(int i=1;i<=n+r;i++){
        while(i==arr[k].y){
            dp[i] = max(dp[i-1],dp[i]);
            dp[i+r] = max(max(dp[arr[k].x]+arr[k].z,dp[i]),dp[i+r]); 
            k++;
        }
        dp[i] = max(dp[i-1],dp[i]);
    }
    printf("%d",dp[n+r]);
    return 0;
}