#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 50005;
int arr[maxd],l[7],r[7],ans;
int main(){
	int n,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		arr[i] = (arr[i-1]+k)%7;
	}
	for(int i=1;i<=n;i++) r[arr[i]] = i;
	for(int i=n;i>0;i--) l[arr[i]] = i;
	for(int i=0;i<7;i++) ans = max(ans,r[i]-l[i]);
	printf("%d",ans);
	return 0;
}