//P1198 [JSOI]最大数
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxd = 200005*3;
const int maxn = 200005;
int arr[maxd],n,m,len,a,t;
char str[10];
void up(int pid){
	arr[pid] = max(arr[pid<<1],arr[pid<<1|1]);
}
void modify(int pid,int l,int r,int pos,int c)
{
	if(l==r){
		 arr[pid] = c;
		 return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)
		modify(pid<<1,l,mid,pos,c);
	else
		modify(pid<<1|1,mid+1,r,pos,c);
	up(pid);
}
int query(int pid,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
		return arr[pid];
	int ans1=0,ans2=0,mid = (l+r)/2;
	if(x<=mid)
		ans1 = query(pid<<1,l,mid,x,y);
	if(y>mid)
		ans2 = query(pid<<1|1,mid+1,r,x,y);
	up(pid);
	return max(ans1,ans2);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",str,&a);
		if(str[0] == 'Q')
		{
		    if(!a)printf("0\n");
			else {t = query(1,1,maxn,len-a+1,len);
			printf("%d\n",t);
			}
		}
		else{
	        modify(1,1,maxn,++len,(t+a)%m);
		}
	}
	return 0;
}