#include <cstdio>
#include <algorithm>
using namespace std;
int arr[6],flag[4] = {0,5,3,1};
int x,y;
int main(){
    while(true)
    {  
        int k=1,ans=0,d;
        for(int i=0;i<6;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]) k = 0;
        }
        if(k) break;
        
        ans = arr[5]+arr[4]+arr[3]+(arr[2]+3)/4;
        y = 5 * arr[3] + flag[arr[2]%4];
        if( arr[1] > y) ans +=  (arr[1]-y+8)/9;

        x = 36*ans-36*arr[5]-25*arr[4]-16*arr[3]-9*arr[2]-4*arr[1];
        if(arr[0]>x) ans += ( arr[0] - x + 35) /36;
        printf("%d\n",ans);
    }
    return 0;
}