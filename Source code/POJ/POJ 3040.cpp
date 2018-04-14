#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 25
struct node{
	int x,y;
	bool operator < (const node &c) const 
	{
		return y>c.x;
	}
}arr[25];
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int i=0;i<n;i++)
			scanf("%d %d",&arr[i].x,&arr[i].y);
		sort(arr,arr+n);
		int right=0,ans=0;
		for(int i=0;i+right<n;i++)
		{
			
		}
	}
	return 0;
}