//P1088 luogu
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int a[10005],n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	while(m--)  next_permutation(a,a+n);
	for(int i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d",a[n-1]);
	return 0;
}