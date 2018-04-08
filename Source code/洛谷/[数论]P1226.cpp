//P1226 luogu
//DinnerHunt
#include<cstdio>
using namespace std;
int main()
{
    long long a,b,c,result=1,d,e,f;
    scanf("%lld %lld %lld",&a,&b,&c);
    d=a;e=b;f=c;
    while(b)
    {
        if(b%2==1) result=result*a%c;
        b/=2;
        a=a*a%c;
    }
    printf("%d^%d mod %d=%d",d,e,f,result);
    return 0;
}