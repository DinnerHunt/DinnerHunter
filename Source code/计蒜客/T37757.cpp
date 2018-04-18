#include <iostream>
using namespace std;
int main(){
    int number,arr[1010],dp1[1010],dp2[1010];
    cin >> number;
    for(int i=1;i<=number;i++) cin >> arr[i];
    for(int i=1;i<=number;i++)
    {
        dp1[i]=1;
        for(int j=0;j<i;j++)
            if(arr[j]>=arr[i])
                dp1[i] = max(dp1[j]+1,dp1[i]);
    }
    for(int i=number;i>=1;i--)
    {
        dp2[i]=1;
        for(int j=number;j>i;j--)
            if(arr[j]>=arr[i])
                dp2[i] = max(dp2[j]+1,dp2[i]);
    }
    int res=0;
    for(int i=1;i<=number;i++)
        res = max(res,dp1[i]+dp2[i]);
    cout << number - res+1;
    return 0;
}