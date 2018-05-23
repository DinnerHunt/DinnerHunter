#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 2000005;
int vis[maxd],tree[maxd],arr[maxd],last[maxd],ans[maxd];
int n,m;
int  getsum(int x){
	int ans = 0;
	for(;x;x-=(x&-x))
		ans += tree[x];
	return ans;
}
void change(int x){
	for(;x<=n;x+=(x&-x))
		tree[x] +=1;
}
struct edge{
	int l,r,id;
	bool operator < (const edge &other){
	    return l<other.l;
	}
}bian[maxd];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if(!vis[arr[i]])
		{
			vis[arr[i]] = 1;
			change(i);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>0;i--){
		if(!vis[arr[i]]) last[i] = n+1;
		else last[i] = vis[arr[i]];
		vis[arr[i]] = i;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&bian[i].l,&bian[i].r);
		bian[i].id = i;
	}
	sort(bian,bian+m);
	int len = 1;
	for(int i=0;i<m;i++){
		while(bian[i].l > len){ change(last[len]);len++;}
		ans[bian[i].id]= getsum(bian[i].r)-getsum(bian[i].l-1);
	}
	for(int i=0;i<m;i++)
	    printf("%d\n",ans[i]);
	return 0;
}