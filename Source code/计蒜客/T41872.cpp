//jisuanke t41872 校长的问题
//DinnerHunt
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
struct node{
	int x,y,z,ans;
}arr[maxn];
bool cmp1(const node &a,const node &b){
	return a.x<b.x;
}
bool cmp2(const node &a,const node &b){
	return a.z<b.z;
}
int tree[maxn],n,m;
int query(int x){
	int ans = 0;
	for(;x;x-=x&-x)
		ans+=tree[x];
	return ans;	
}
int modify(int x,int k){
	for(;x<=n;x+=x&-x)
		tree[x] += k;
}
int main(){
	scanf("%d %d",&n,&m);
	queue<int> que;
	int k;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		que.push(k);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&arr[i].x,&arr[i].y);
		arr[i].z=i;
	}
	sort(arr+1,arr+m+1,cmp1);
	k=0;
	for(int i=1;i<=m;i++){
		while(k<arr[i].x){
			k++;
			modify(que.front(),1);
			que.pop();
		}
		arr[i].ans = query(arr[i].y);
	}
	sort(arr+1,arr+1+m,cmp2);
	for(int i=1;i<=m;i++){
		printf("%d\n",arr[i].ans);	
	}
	return 0;
}