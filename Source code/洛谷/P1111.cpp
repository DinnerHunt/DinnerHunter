#include<cstdio>
#include <algorithm>
using namespace std;
const int maxd = 100005;
int fa[maxd],sum[maxd];
struct node
{
	int x,y,z;
	bool operator < (const node &other) const{
		return z < other.z;
	}
}arr[maxd];
void init(){
	for(int i=0;i<maxd;i++){
		fa[i] = i;
		sum[i] = 1;
	}
}
int gf(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = gf(fa[x]);
}
void until(int x,int y)
{

	sum[gf(y)] += sum[gf(x)];
	fa[gf(x)] = gf(y);
}
int main(){
	int n,m;
	init();
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
	sort(arr,arr+m);
	for(int i=0;i<m;i++)
	{
		if(gf(arr[i].x)!=gf(arr[i].y))
		{
			until(arr[i].x,arr[i].y);
			if(sum[gf(arr[i].y)] == n)
			{
				printf("%d",arr[i].z);
				return 0;
			}
		}
	}
	printf("%d",-1);
	return 0;
}