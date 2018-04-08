#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e5+100;
long long num[maxn],tp[maxn],id[maxn];
int ans[maxn],tree[maxn];
int n;
map<long long,int> mp;
void change(int x,int k){
	for(;x<=n;x+=x&-x)
		tree[x]+=k;
}
int getsum(int x){
	int ans = 0;
	for(;x;x-=x&-x)
		ans+=tree[x];
	return ans;
}
void init(){
	for(int i=0;i<n;++i)
		tp[i] = num[i];
	sort(tp,tp+n);
	int m = unique(tp,tp+n) - tp;
	for(int i=0;i<m;i++){
		mp[tp[i]] = i+1;
		id[i+1] = tp[i];
	}
	for(int i=0;i<n;i++){
		ans[i] = mp[num[i]];
	}
}
int main(){
	long long wa =0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
    }
	init();
	for(int i=n;i;i--){
		int k = ans[i-1];
        //printf("%d ",ans[i-1]);
		wa+=getsum(k);
		change(k,1);
	}
    printf("%lld",wa);
	return 0;
}
