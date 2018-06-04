#include <cstdio>
using namespace std;
const int maxd = 10005;
const long long mod = 1000000007;
void inv[maxd]; 
void init{
    inv[1] = 1;
	for (int i = 2; i <= 2*maxd; ++i) 
   		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
int main(){
    long long n,m,last = 1;
    scanf("%lld %lld",&n,&m);
    n = m+n-1;
    for(long long i=1;i<=m;i++)
        last = ((m+n-i)*last)%mod*inv[i]%mod;
    printf("%d",last);
    return 0;
}