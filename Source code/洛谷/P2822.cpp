#include <cstdio>
using namespace std;
const int maxd = 2005;
long long ans[maxd][maxd];
long long arr[maxd][maxd];
int main(){
	long long t,k,m,n;
	scanf("%lld %lld",&t,&k);
	for(int i=0;i<=2001;i++)
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i) arr[i][j] = 1;
			else arr[i][j] = (arr[i-1][j-1]+arr[i-1][j])%k;
		}
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=2000;j++)
		{
			ans[i][j] = ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
			if(arr[i][j] == 0 && j<=i)
				ans[i][j] ++;
		}
	for(int i=0;i<t;i++)
	{
		scanf("%ld %ld",&m,&n);
		printf("%lld\n",ans[m][n]);
	}
	return 0;
}