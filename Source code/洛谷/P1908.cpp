//P1908 luogu
//DinnerHunt
#include <cstdio>
using namespace std;
int a[40005],tmp[40005];
long long ans=0;
void merge_sort(int l,int r)
{
	if(l==r) return ;
    int mid=(l+r)/2;
    merge_sort(l,mid),merge_sort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) tmp[k++]=a[i++];
        else{
            ans+=mid-i+1;
            tmp[k++]=a[j++];
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=tmp[i]; 
			
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	merge_sort(1,n);
	printf("%d",ans);
	return 0;
}