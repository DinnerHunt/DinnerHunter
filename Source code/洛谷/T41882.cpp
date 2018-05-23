#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxd = 50005;
inline int abs(int x){
	return x>0?x:-x;
}
int arr1[2*maxd],arr2[2*maxd];
int ls_x[2*maxd],ls_y[2*maxd];
map<int,int> x_map,x_map;
int id_x[2*maxd],id_y[2*maxd];
struct edge{
	int pos,l,r,flag;
}x_edge[2*maxd],y_edge[2*maxd];

int tree[4*maxd],lazy[4*maxd];
i
void up(int pid){
	tree[pid] = tree[pid<<1] + tree[pid<<1|1];
}
void modify(int pid,int l,int y,int x,int y){
	if(x<=l&&r<=y)
	{
		lazy[pid]+=1;
		return ;
	}
	down(pid);
	int mid = (l+r)/2;
	if(x<=mid)
		modify(pid<<1,l,mid,x,y);
	if(y>mid)
		modify(pid<<1|1,mid+1,r,x,y);
	up(pid);
}

int main(){
	int n,x1,y1,x2,y2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d %d",&arr1[i*2],&arr2[i*2],&arr1[i*2+1],&arr2[i*2+1]);
	sort(arr1,arr1+(n*2));
	sort(arr2,arr2+(n*2));
	int k1 = unique(arr1,arr1+(n*2));
	int k2 = unique(arr2,arr2+(n*2));
	for(int i=0;i<k1;i++)
	{
		x_map[arr1[i]]=i+1;
		id[i+1] = arr[i];
	}
	for(int i=0;i<k2;i++)
	{
		y_map[arr1[2]]=i+1;
		id[i+1] = arr[i];
	}
	for(int i=0;i<n;i++)
	{
		x_edge[i*2].l = x_map[arr1[i*2]];
		x_edge[i*2].r = x_map[arr1[i*2+1]];
		x_edge[i*2].pos = y_map[arr2[i*2]];
		x_edge[i*2].flag = 0;
		x_edge[i*2+1].l = x_map[arr1[i*2]];
		x_edge[i*2+1].r = x_map[arr1[i*2+1]];
		x_edge[i*2+1].pos = y_map[arr2[i*2+1]];
		x_edge[i*2+1] .flag = 1;

		y_edge[i*2].l = y_map[arr2[i*2]];
		y_edge[i*2].r = y_map[arr2[i*2+1]];
		y_edge[i*2].pos = x_map[arr1[i*2]];
		y_edge[i*2].flag = 0;
		y_edge[i*2+1].l = y_map[arr2[i*2]];
		y_edge[i*2+1].r = y_map[arr2[i*2+1]];
		y_edge[i*2+1].pos =xy_map[arr1[i*2+1]];
		y_edge[i*2+1] .flag = 1;
	}
	return 0;
}