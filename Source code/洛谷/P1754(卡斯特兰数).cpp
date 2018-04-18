#include <cstdio>
using namespace std;
long long arr[30];
int main()
{
	scanf("%d",&arr[0]);
	arr[2]=2;
	arr[1]=1;
	for(int i=3;i<=arr[0];i++)
		arr[i] = arr[i-1]*(4*i-2)/(i+1);
	printf("%lld",arr[arr[0]]);
	return 0;
}