//Vijos 1498 排座位
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct s{
	int num;
	int id;
	bool operator<(const s &a) const{
	return num>a.num;
	}
}xk[1005],yk[1005];
int m,n,k,l,d;
int x,y,p,q,i,w;
int an1[1005],an2[1005];
int main(){
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x==p){
			w=min(y,q);
			yk[w].num++;
			yk[w].id=w;
		}
		else {
			w=min(x,p);
			xk[w].num++;
			xk[w].id=w;
		}
	}
	sort(xk+1,xk+m+1);
	sort(yk+1,yk+n+1);
	for(i=1;i<=k;i++) an1[i]=xk[i].id;
	for(i=1;i<=l;i++) an2[i]=yk[i].id;
	sort(an1+1,an1+k+1);
	sort(an2+1,an2+l+1);
	for(i=1;i<=k;i++) printf("%d ",an1[i]);printf("\n");
	for(i=1;i<=l;i++) printf("%d ",an2[i]);printf("\n");
	return 0;
}