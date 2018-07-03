#include <cstdio>
using namespace std;
const long long mod = 100003;
long long pow_mod(long long a,long long b)
{
    long long res = 1,temp = a;
    for(;b;b/=2)
    {
        if(b&1)res= res*temp % mod;
        temp = temp * temp %mod;
    }
    return res;
}
int main(){
    long long M,N;
    scanf("%lld %lld",&M,&N);
    printf("%lld",(pow_mod(M,N)- ((M%mod*pow_mod(M-1,N-1))%mod)+mod)%mod);
    return 0;
}