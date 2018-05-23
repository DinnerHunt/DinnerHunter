#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 500005;
int n,tree[maxd],have[maxd],last[maxd],arr[maxd];
int getsum(int x,){
	int ans = 0;
	for(;x;x-=(x&-x))
		ans += tree[x];
	return x;
}
void change(int x){
	for(;x<=n;x+=(x&-x))
		tree[x]+=1;
}
int main(){
	int a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i])
		if(!have[arr[i]]){
			have[arr[i]]=1;
			change(i);
		}
	}
	memset(have,0,sizeof(have));
	for(int i=n;i>=1;i--)
	{
		if(!have[arr[i]]) change(n+1);
		else last[arr[i]] = have[arr[i]];
		have[arr[i]] = i;
	}
	return 0;
}