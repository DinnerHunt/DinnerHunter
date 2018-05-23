#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxd = 100005;
int arr[maxd*2],l[maxd],r[maxd],vis[maxd],ans;
int tree[maxd*4],lazy[maxd*4];
map<int,int> mp;
int id[maxd*2];
void down(int pid){
    if(lazy[pid]){
	tree[pid<<1] = lazy[pid];
	tree[pid<<1|1] = lazy[pid];
	lazy[pid<<1] = lazy[pid];
	lazy[pid<<1|1] = lazy[pid]; 
    lazy[pid]=0;
    }
}
void modfiy(int pid,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)
	{
		tree[pid] = z;
		lazy[pid] = z;
		return ;
	}
	down(pid);
	int mid = (l+r)/2;
	if(x<=mid)
		modfiy(pid<<1,l,mid,x,y,z);
	if(y>mid)
		modfiy(pid<<1|1,mid+1,r,x,y,z);
}
void query(int pid,int l,int r){
	if(l==r){
		if(tree[pid])
		if(!vis[tree[pid]])
		{
			vis[tree[pid]] = 1;
			ans++;
		}
		return;
	}
	int mid = (l+r)/2;
    down(pid);
	query(pid<<1,l,mid);
	query(pid<<1|1,mid+1,r);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&l[i],&r[i]);
	for(int i=0;i<n;i++)
		arr[i] = l[i];
	for(int i=n;i<2*n;i++)
		arr[i] = r[i-n];
	sort(arr,arr+2*n);
	int k = unique(arr,arr+2*n) - arr;
	for(int i = 0; i < k ; i++){
		mp[arr[i]] = i+1;
		id[i+1] = arr[i];
	}
   // for(int i=0;i<n;i++)
    //    printf("%d %d\n",mp[l[i]],mp[r[i]]);
	for(int i=0;i<n;i++)
		modfiy(1,1,k,mp[l[i]],mp[r[i]],i+1);
	query(1,1,k);
	printf("%d",ans);
	return 0;
}