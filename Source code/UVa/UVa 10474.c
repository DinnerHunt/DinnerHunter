//UVa10474	大理石在哪里
#include <iostream>
#include <algotithm>
using namespace std;
int main(){
	int x,y,cout=1.number;
	while(scanf("%d %d",&x,&y)!=EOF&&x&&y){
		int arr[x];
		for(int i=0;i<x;i++)
			scanf("%d",&arr[i]);
		sort(a,a+n);
		printf("CASE# %d:\n",cout++);
		while(y--){
			scanf("%d",&number);
			itn p= lower_bound(arr,arr+n)-a;
			if(a[p]==number)printf("%d found at %d\n",x,p+1);
			else printf("%d not found\n", x);
		}
	}
	return 0;
}