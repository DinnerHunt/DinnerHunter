//P1147 luogu
//DinnerHunt
#include <cstdio>
using namespace std;
int n,sum,j;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)
	{
		sum = 0;
		for(j=i;j<n;j++)
		{
			sum+=j;
			if(sum>=n)break;
		}
		if(sum==n) printf("%d %d\n",i,j);
	}
	return 0;
}