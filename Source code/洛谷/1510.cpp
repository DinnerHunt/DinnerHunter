//P1510 精卫填海
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 20005;
int v[maxd],s[maxd],dp[maxd];
int main(){
	int a,n,c,flag=-1;
	scanf("%d %d %d",&a,&n,&c);
	for(int i = 0; i < n; ++i)
		scanf("%d %d",&v[i],&s[i]);
	dp[0] = 0;
	for(int i=0;i<n;i++)
		for(int j=c;j>=s[i];j--)
		    dp[j] = max(dp[j],dp[j-s[i]]+v[i]);
    for(int i=1;i<=c;i++)
        if(dp[i]>=a){ flag=i;break; }
    
	if(flag == -1) printf("Impossible");
	else printf("%d",c-flag);
	return 0;
}