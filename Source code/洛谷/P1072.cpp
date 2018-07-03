//gcd(x/a1,a0/a1) = 1;
//gcd(b1/b0,b1/x) = 1;
#include <cstdio>
using namespace std;
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
int ans,a,b,c,d,n;;
void ok(int x){
	if(gcd(x/b,a/b)==1&&gcd(d/c,d/x)==1) ans++;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		ans = 0;
		for(int j=1;j*j<=d;j++){
			if(d%j==0)
			{
				if(j%b==0) ok(j);
				if((d/j)%b==0&&j*j!=d) ok(d/j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}