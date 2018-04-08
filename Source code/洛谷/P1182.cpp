//P1182 luogu
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int arr[maxn];
int n,m,sum=0,mi;
int check(int x){
	int k=0,ant=1;
	for(int i=1;i<=n;i++){
		if(k+arr[i]<=x){
			k+=arr[i];
		}
		else{
			k=arr[i];
			ant++;
		}
	}
	return ant<=m;
}
int main(){
	int l=0,r=0,mid;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		l=max(l,arr[i]);
		r+=sum;
	}
    while(l<r){
    	mid=(l+r)>>1;
    	if(check(mid))
    		r=mid;
    	else 
    		l=mid+1;
    }
    printf("%d",l);
   
	return 0;
}