#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 100005;
struct node{
	int len_l,len_r,len,down;
}arr[maxd],arr1[maxd];


void up(int pid,int l,int r){
	int mid = (l+r)/2,len_black,len_write;
	if(arr[pid<<1].len_l == (mid-l+1))
		arr[pid].len_l = arr[pid<<1].len_l + arr[pid<<1|1].len_l;
	else
		arr[pid].len_l = arr[pid<<1].len_l;
	if(arr[pid<<1|1].len_r == (r-mid))
		arr[pid].len_r =  arr[pid<<1|1].len_r + arr[pid<<1].len_r;
	else
		arr[pid].len_r = arr[pid<<1|1].len_r;

	len_black = arr[pid<<1].len_r+arr[pid<<1|1].len_l;
	arr[pid].len = max(max(max(arr[pid<<1].len,arr[pid<<1|1].len),max(arr[pid].len_l,arr[pid].len_r)),len_black);

	if(arr1[pid<<1].len_l == (mid-l+1))
		arr1[pid].len_l = arr1[pid<<1].len_l + arr1[pid<<1|1].len_l;
	else 
		arr1[pid].len_l = arr1[pid<<1].len_l;

	if(arr1[pid<<1|1].len_r == (r-mid))
		arr1[pid].len_r = arr1[pid<<1|1].len_r + arr1[pid<<1].len_r;
	else 
		arr[pid].len_r = arr1[pid<<1|1].len_r;

	len_write = arr1[pid<<1].len_r + arr1[pid<<1|1].len_l;
	arr1[pid].len = max(max(max(arr1[pid<<1].len,arr1[pid<<1|1].len),max(arr1[pid].len_l,arr1[pid].len_r)),len_write);

}

void build(int pid,int l,int r){
	if(l==r){
		scanf("%d",&arr[pid]);
		if(arr[pid])
		{
			arr[pid].len_l = 1;
			arr[pid].len_r = 1;
		}
		else
		{
			arr1[pid] = 1;
			arr1[pid]_l = 1;
			arr1[pid]_r = 1;
		}
		return ;
	}
	int mid = (l+r)/2;
	build(pid,l,mid);
	build(pid,mid+1,r);
	up(pid,l,r);
}

void modify(int pid,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)
	{
		if(z == 0)
		{
			arr[pid].down = 2;
			arr[pid].len_l = 0;
			arr[pid].len_r = 0;
			arr[pid].len = 0;
			arr1[pid].down = 1;
			arr1[pid].len_l = (r-l+1);
			arr1[pid].len_r = (r-l+1);
			arr1[pid].len = (r-l+1);
		}
		else
		{
			arr[pid].down = 1;
			arr[pid].len_l = (r-l+1);
			arr[pid].len_r = (r-l+1);
			arr[pid].len = (r-l+1);
			arr1[pid].down = 2;
			arr1[pid].len_l = 0;
			arr1[pid].len_r = 0;
			arr1[pid].len = 0;

		}
	}

}
int main(){
	int m,n,a,b,c;
	scanf("%d",&m);
	build(1,1,m);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);

	}
	return 0;
}