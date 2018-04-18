#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int ans[1005];
int main()
{
    int n,a,len=0;
    stack<int> stk;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        stk.push(a);
    }
    ans[0] = stk.top();
    stk.pop();
    for(int i=1;i<n;i++)
    {
        int k = stk.top();
        stk.pop();
        if(k>=ans[len])
            ans[++len] = k;
        else 
            *lower_bound(ans,ans+len,k) = k;
    }
    printf("%d",len+1);
    return 0;
}