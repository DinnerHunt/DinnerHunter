//POJ 1852 Ants 
#include<iostream>
#include<cstdio>
using namespace std;
#define Max(a,b) a>b?a:b;
int main()
{
    int T,m,n,a,b,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(a=b=0;n--;)
        {
            scanf("%d",&k);
            k=Max(m-k,k);    //距离最长的一边
            b=Max(b,k);        //最长的距离所需要的时间也最大
            a=Max(a,m-k);    //m-是距离最短的一边
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}