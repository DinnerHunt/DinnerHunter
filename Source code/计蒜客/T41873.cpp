//jisuanke t41873
//DinnerHunt 
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e5+5;
int tree[maxn],n,m,flag[maxn];
int stk1[maxn],top1=0,stk2[maxn],top2=0;
int query(int x){
	int ans =0;
	for(;x;x-=x&-x)
		ans += tree[x];
	return ans;
}
int modify(int x,int k){
	for(;x<=m;x+=x&-x)
		tree[x] = k;
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<m;i++)
		scanf("%d",&stk1[++top1]);
	while(top1){
		int k = k+1+stk1[top1--];
		k+=query(m);
		stk2[++top2] = k;
		flag[k]=1;
		modify(k,1);
	}
	for(int i=1;i<=m;i++)
		if(!flag[i])
		{
			printf("%d\n",i);
			break;
		}
	while(top2)
		printf("%d\n",stk2[top2]);
	
	return 0;
}