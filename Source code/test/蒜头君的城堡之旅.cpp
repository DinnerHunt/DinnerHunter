#include<stdio.h>
int dp[50][50][50];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int m,n,i,j,k,l,t1,t2;
    int c[50][50];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",c[i]+j);
    ***dp=**c;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            t1=i+j-n;
            t1=t1>0?t1:0;
            t2=i+j+1;
            t2=t2<n?t2:n;
            for(k=t1;k<t2;k++)
            {
                l=i+j-k;
                if(i&&k)
                    dp[i][j][k]=max(dp[i-1][j][k-1],dp[i][j][k]);
                if(i)
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k]);
                if(j&&k)
                    dp[i][j][k]=max(dp[i][j-1][k-1],dp[i][j][k]);
                if(j)
                    dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k]);
                dp[i][j][k]+=c[i][j]+c[k][l];
                if(i==k)
                    dp[i][j][k]-=c[i][j];
            }
        }
    }
    printf("%d",dp[n-1][m-1][n-1]);
}

DinnerHunt 2017/10/16 20:50:30
