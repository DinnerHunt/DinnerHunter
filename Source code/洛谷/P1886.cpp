#include <cstdio>
using namespace std;
const int maxd = 1000005;
struct node{
	int v,id;
}big[maxd],sma[maxd];
int arr[maxd],lb,rb,ls,rs;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<k;i++)
	{
		while(rb>lb && arr[i] >= big[rb-1].v) rb--;
		big[rb].v = arr[i]; big[rb++].id =i;
		while(rs>ls && arr[i] <= sma[rs-1].v) rs--;
		sma[rs].v = arr[i];sma[rs++].id = i;
	}
	for(int i=k;i<=n;i++)
	{
		while(rs>ls && arr[i] <= sma[rs-1].v) rs--;
		while(rs>ls && sma[ls].id <= i-k) ls++;
		sma[rs].v = arr[i];
		sma[rs++].id = i;
		printf("%d",sma[ls].v);
		if(i==n)printf("\n");
		else printf(" ");
	}
	for(int i=k;i<=n;i++)
	{
		while(rb>lb && arr[i] >= big[rb-1].v) rb--;
		while(rb>lb && big[lb].id <= i-k) lb++;
		big[rb].v = arr[i];
		big[rb++].id = i;
		printf("%d ",big[lb].v);
	}
	return 0;
}