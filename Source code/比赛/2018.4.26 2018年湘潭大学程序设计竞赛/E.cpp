#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 30005;
struct node{
	int x,y;
	bool operator < (const node &other)const
	{
		if(y == other.y) return x<y;
		return y > other.y;
	}
}arr[maxd];
int main(){
	int t,n,n,m,a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&m);
		for(int j=0;j<n;j++)
			scanf("%d %d",&arr[j].x,&arr[j].y);
		sort(arr,arr+n);	
		for(int k=0;k<m;k++)
		{
			scanf("%d",&a);
			for(int l=0;l<=n;l++)
			{
				if(l==n) printf("0\n");
				else if(a>=arr[l].x){
					printf("%d\n",arr[l].y);
					break;
				}
			}
		}
	}
	return 0;
}