#include <cstdio>
using namespace std;
const int mod = 1000007;
const int maxd = 105;
int n, m, a[maxd], dp[maxd];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) 
    	scanf("%d", &a[i]);
    dp[0] = 1;  
    for(int i = 1; i <= n; i++) 
        for(int j = m; j >= 1; j--)  
            for(int k = 1; k <= a[i] && j - k >= 0; k++)
                dp[j] = (dp[j - k] + dp[j]) % mod; 
    printf("%d", dp[m]);
    return 0;
}