#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 300005;
const int maxn = 50005;
int arr[maxd],arr1[maxd],tree[maxd],ans[maxn];
int n,m;
struct node{
	int l,r,k,id;
	bool operator < (const node &other ) const {
		if(l==other.l) return r<other.r;
		return l<other.l;
	}
}query[maxn];
void change(int x,int k){
	for(;x<=n;x+=(x&-x))
		tree[x] += k;
}
int getsum(int x){
	int ans = 0;
	for(;x;x-=(x&-x))
		ans += tree[x];
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		arr1[i] = arr[i];
	}
	sort(arr1+1,arr1+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&query[i].l,&query[i].r,&query[i].k);
		query[i].id = i;
	}
	sort(query+1,query+1+m);
	int len1 = 0,len2 =1;
	for(int i=1;i<=m;i++)
	{
		while(len1 < query[i].r)
			change(lower_bound(arr1+1,arr1+1+n,arr[++len1]) - arr1,1);
		while(len2 < query[i].l)
			change(lower_bound(arr1+1,arr1+1+n,arr[len2++]) - arr1,-1);
		int l=1,r=n,mid;
		while(l<r){
			mid = (l+r) >> 1;
			if(getsum(mid) >= query[i].k) r=mid;
			else l = mid +1; 
		}
		ans[query[i].id] = arr1[l];
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}