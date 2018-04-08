#include<stdio.h>
#include<algorithm>
using namespace std;
int a[110]={0},b[110]={0};
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n+m)
	{
		int i,j,t=0;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<m;i++)
		scanf("%d",&b[i]);
		sort(b,b+m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			if(a[i]==b[j])
			{
				t++;
				a[i]=-1;//此处非常重要
			}	
		}
		if(t==n)
		printf("NULL\n");
		else
		{
			for(i=0;i<n;i++)
			if(a[i]>=0)
			printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
} 