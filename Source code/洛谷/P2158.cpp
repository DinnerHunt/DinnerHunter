#include <cstdio>
using namespace std;
const int maxd = 40005;
int n,arr[maxd],sum;
int main(){
	scanf("%d",&n);
	for(int i=2,j;i*i<=n;i++)
		if(!phi(i))
			for (;j<=n;j+=i)
				phi[j] = !phi[j]?j:phi[j]/i*i(i-1);
	for(int i=3;i<=n;i++)
		sum+=phi[i-1];
	printf("%d",ans*2+3);
	return 0;
}