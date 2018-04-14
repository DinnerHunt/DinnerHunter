//POJ 1328
//DinnerHunt
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxd = 1005;
struct node
{
    double x,y;
    bool operator < (const node &a) const
    {
        if(y==a.y)
            return x<a.x;
        return y<a.y;
    }
}arr[maxd];
int main(){
    int x,y,a,b,flag =0;
    while(scanf("%d %d",&x,&y)==2&&x&&y)
    {
    	int cheak = 1;
        for(int i=0;i<x;i++)
        {
            scanf("%d %d",&a,&b);
            if(b>y) cheak = 0;
            arr[i].x = a - sqrt(y*y-b*b);
            arr[i].y = a + sqrt(y*y-b*b);
        }
        int ans=-1,r;
        if(cheak)
        {
	        sort(arr,arr+x);
	        ans = 1;
	        r = arr[0].y;
	        for(int i=1;i<x;i++)
	            if(arr[i].x>r)
	            {
	                ans++;
	                r = arr[i].y;
	            }
    	}
        printf("Case %d: %d\n",++flag,ans);
    }
    return 0;
}
