#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 100005;
const int inf = 1e9;
int arr[maxd];
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
		scanf("%d,",&arr[i]);
	sort(arr,arr+n);
	int l=0,r=inf;
	while(l<r){
		int mid = (l+r+1)>>1,ans=1,last=arr[0]
		for(int i=1;i<n;i++){
			if(arr[i]-last>=mid)
			{
				last = arr[i];
				ans++;
			}
			if(ans >= s) break;
		}
		if(ans<s) r=mid-1;
		else l = mid;
	}
	printf("%d",l);
	return 0;
}