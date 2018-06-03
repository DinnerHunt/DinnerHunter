#include <cstdio>
using namespace std;
const int maxd = 1000005;
int n,m;
int	prime[maxd];
int check[maxd];
int arr[maxd]
void init(){
	int pos =0;
	for(int i=2;i<=m;i++)
	{
		if(!check[i])
			prime[pos]++ = i;
		for(j = i+i ; j<=m; j++)
			check[j] = 1;
	}
	for(int i=2;i<=m;i++)
		if(!check[i])
			arr[i] = arr[i-1]+1;
		else 
			arr[i] = arr[i-1];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a<0||b>m) printf("Crossing the line\n");
		else printf("%d",arr[b] - arr[a-1]);
	}
	return 0;
}