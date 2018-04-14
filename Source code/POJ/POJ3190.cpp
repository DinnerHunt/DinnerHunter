//POJ 3190
//luogu 2859
//DinnerHunt
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 50005;
struct node{
    int x,y,z,id;
    bool operator < (const node &d) const
    {
        return y > d.y;
    }
}arr[maxd];
bool cmp(node a,node b){
    return a.x < b.x;
}
bool cmpd(node a,node b){
    return a.id <b.id;
}
int main()
{
    int n,ans=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i].x,&arr[i].y);
        arr[i].id=i;
    }
    sort(arr,arr+n,cmp);
    priority_queue<node> que;
    arr[0].z = ans;
    que.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i].x<=que.top().y)
        {
            ans++;
            arr[i].z = ans;
            que.push(arr[i]);
        }
        else{ 
            arr[i].z= que.top().z;
            que.pop();
            que.push(arr[i]);
        }
    }
    sort(arr,arr+n,cmpd);
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i].z);
    }
    return 0;
}