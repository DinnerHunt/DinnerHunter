//vijos 数与连分数 1696
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
long a[1000];
void aha1(int x,int y,int t)
{
    for(int i=t;i>=1;i--)
    {
        long c=x;
        x=y;
        y=c;
        x=x+y*a[i];
    }
    printf("%ld",x);
    if(y!=1)
        printf("/%ld",y);
    printf("\n");
    return;
}
void aha2(int x,int y)
{
    long e=1,k;
    k=x/y;
    printf("[%ld",k);
    x=x-k*y;
    while(x!=0)
    {
        int c=x;
        x=y;
        y=c;
        k=x/y;
        x=x-k*y;
        if(e==1)
            printf(";%ld",k),e=0;
        else
            printf(",%ld",k);
    }
    printf("]\n");
}
int main(){
    char x[1000];
    while(gets(x))
    {
        memset(a, 0, sizeof(a));
        if(x[0]=='[')
        {
            int t=1,q=1;
            while(x[q]!=']')
            {
                if(x[q]>='0'&&x[q]<='9')
                {
                    a[t]=a[t]*10+x[q]-'0';
                }
                else
                    t++;
                q++;
            }
            aha1(a[t],1,t-1);
        }
        else
        {
            int t=1,q=0;
            while(x[q]!='\n'&&x[q]!=EOF&&x[q]!='\0')
            {
                if(x[q]>='0'&&x[q]<='9')
                {
                    a[t]=a[t]*10+x[q]-'0';
                }
                else
                    t++;
                q++;
            }
            int m=a[1],n=a[2];
            aha2(m,n);
        }
    }
    return 0;
}