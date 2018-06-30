#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 1005;
struct node{
    int x,y;
    bool operator < (const node &other) const
    {
        return x*y < other.x*other.y;
    }
}arr[maxd];
__int128 ans=0;
void print()
{
    int a= ans%10;
    ans /= 10;
    if(ans) print();
    printf("%d",a);
}
int main(){
    int a,b,n;
    scanf("%d",&n);
    scanf("%d %d",&a,&b);
    for(int i=0;i<n;i++)
        scanf("%d %d",&arr[i].x,&arr[i].y);
    sort(arr,arr+n);
    __int128 sum = a;
    for(int i=0;i<n;i++){
        if(ans < sum/arr[i].y)
            ans = sum/arr[i].y;
        sum *= arr[i].x;
    }
    print();
    return 0;
}