//luogu P1002
//DinnerHunt
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int x1,x2,m1,m2;
    int mx[8]={1,1,-1,-1,2,-2,2,-2},my[8]={2,-2,2,-2,1,1,-1,-1};
    long long ans[25][25];
    cin >> x1 >> x2 >> m1 >> m2;
    memset(ans,0,sizeof(ans));
    for(int i=0;i<8;i++){
        int a=m1+mx[i],b=m2+my[i];
        if(a>=0&&a<25&&b>=0&&b<=25)
            ans[a][b]=-1;
    }
    ans[m1][m2]=-1;
    ans[0][0]=1;
    
    for(int i=0;i<=x1;i++)
        for(int j=0;j<=x2;j++)
        {
            if(i!=0&&ans[i][j]!=-1&&ans[i-1][j]!=-1)
            {
                ans[i][j]+=ans[i-1][j];
            }
            if(j!=0&&ans[i][j]!=-1&&ans[i][j-1]!=-1)
            {
                ans[i][j]+=ans[i][j-1];
            }
        }
    if(!ans[x1][x2]||ans[x1][x2]==-1)
        cout << 0;
    else
    cout << ans[x1][x2];
    return 0;
}