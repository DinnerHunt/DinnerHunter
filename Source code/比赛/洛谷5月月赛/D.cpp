//T30208
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 200005;
struct node{
	int x,y;
	bool operator < (const node &other)const{
		return x < other.x;
	}
}arr[maxd];
int main(){
	int m;
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
		scanf("%d %d",&arr[i].x,&arr[i].y);
	sort(arr,arr+m);
	int right=arr[0].right,ans=1;
	for(int i=1;i<m;i++)
		if(arr[i].x > right)
		{
			ans++;
			right = arr[i].right
		}
	printf("%d",ans-1);
	return 0;
}