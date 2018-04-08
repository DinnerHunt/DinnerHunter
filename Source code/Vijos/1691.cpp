//Vjios 1691
#include <cstdio>
#include <cstdilb>
using namespace std;
const int maxn = 20000 + 10;
int main(){
	int n,arr[maxn],x,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x,&arr[i]);
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		sum+=abs(arr[i]-arr[n/2]);
	}
	printf("%d",sum);
	return 0
}