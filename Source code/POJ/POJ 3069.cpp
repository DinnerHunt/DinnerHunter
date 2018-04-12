//POJ 3069
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1005];
int main(){
	int n,m,x;
	while(scanf("%d %d",&n,&m)==2&&n!=-1)
	{
		for(int i=0;i<m;i++) scanf("%d",&arr[i]);
		sort(arr,arr+m);
		int i = 0,ans=0;
		while(i<m)
		{
			int s = arr[i++]+n;
			while(i<m&&arr[i]<s)i++;
			s = arr[i-1]+n;
			while(i<m&&arr[i]<s)i++;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}