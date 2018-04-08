//Vijos 1409 纪念品分组
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 30000 + 10;
int arr[maxn],m=0,ma,n;
void tx(int i,int j,int h){
	if(i>=j)
		if(h)
			m++;
		return;
	if(arr[i]+arr[j]<=ma){
		m++;
		tx(i+1,j-1,0);
	}
	else{
		tx(i,j-1,1);
		m++;
	}
}
int main(){
	scanf("%d %d",&ma,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int i=0,j=n-1;
	tx(i,j,1);
	printf("%d",++m);
}