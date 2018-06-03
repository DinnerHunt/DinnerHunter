#include <cstdio>
using namespace std;
const int maxd = 1000005;
inline int max(int x,int y)
{
	return x<y?y:x;
}
int mx[maxd],vis[maxd];
void check(int x){
	for(int i=1;i*i<=x;i++)
		if(x%i==0)
		{
			vis[i]++;
			if(i!=x/i)
			vis[x/i]++;
		}
}
int main(){	
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		check(x);
	}
	for(int i=1;i<=maxd;i++)
		mx[vis[i]] = i;
	for(int i=maxd-1;i>=1;i--)
		mx[i] = max(mx[i+1],mx[i]);
	for(int i=1;i<=n;i++)
		printf("%d\n",mx[i]);
	return 0;
}