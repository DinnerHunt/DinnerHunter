#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 50005;
int arr[maxd],ans[maxd],len=0,n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	ans[0] = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>ans[len])
			ans[++len] = arr[i];
		else
		{
			int k = lower_bound(ans,ans+len,arr[i]) - ans;
			ans[k] = arr[i];
		}
	}
	printf("%d",len+1);
	return 0;
}