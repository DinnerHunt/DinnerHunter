#include <cstdio>
#include <cstring>
using namespace std;
int a[10],n,maxn;
int h(){
	int x=0;
	for(int i=0;i<n-1;i++)
		if(a[i]+1!=a[i+1]) x++;
	if(a[n-1]!=n) x++;
	return x;
}
bool ok(){
	for(int i=0;i<n-1;i++)
		if(a[i]>=a[i+1]) return false;
	return true;
}
bool dfs(int x){
	if(x*3+h() > maxn*3) return false;
	if(ok())return true;

	int b[10],c[10];
	memcpy(c,a,sizeof(a));
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int cnt=0;
			for(int k=0;k<n;k++)
				if(k<i||k>j) b[cnt++]=a[k];  //保留不切部分
			for(int k=0;k<=cnt;k++){
				int cnt2 = 0;
				for(int p=0;p<k;p++) a[cnt2++] = b[p];
				for(int p=i;p<=j;p++) a[cnt2++] = c[p];
				for(int p=k;p<cnt;p++) a[cnt2++] = b[p];
				if(dfs(x+1)) return true;
				memcpy(a,c,sizeof(a));
			}
		}
	return false;
}
int main(){
	int Case=0;
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(maxn = 0;maxn < 5; maxn++){
			if(!maxn) if(ok())break;
			if(dfs(0)) break;
		}
		if(Case)printf("\n");
		printf("Case %d: %d",++Case,maxn);
	}
	return 0;
}