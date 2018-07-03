#include <cstdio>
using namespace std;
const int n = 100005;
int fa[n*3];
int gf(int x){
	if(fa[x] == x) return x;
	return fa[x] = gf(fa[x]);
}
void until(int x,int y)
{
	fa[gf(x)] = gf(y);
}
int main(){
	int n,m,x,y,z,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=3*n;i++) fa[i] = i;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(y>n||z>n)ans++;
		else if(x == 1){
			if(gf(y+n) == gf(z) || gf(y+2*n) == gf(z))  ans++;
			else until(y,z),until(y+n,z+n),until(y+2*n,z+2*n);
		}
		else{
			if(y==z|| gf(y) == gf(z) || gf(y+2*n) == gf(z)) ans++;
			else until(y,z+n*2),until(y+n,z),until(y+2*n,z+n);
		}
	}	
	printf("%d",ans);
	return 0;
}