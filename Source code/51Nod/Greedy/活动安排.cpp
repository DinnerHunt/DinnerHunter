#include <cstdio>
#include <alorithm>
using namespace std;
typedef pair<int,int> P;
P arr[10005];
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a.second,&b.first);
	sort(arr,arr+n);
	int time = 0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(time<a.second)
		{
			time = a.first;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}