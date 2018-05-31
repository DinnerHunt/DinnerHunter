#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 10005;
int n,m;
struct node{
	int l,r,pos,flag;
	bool operator < (const node &other) const {
	    if(pos == other.pos) return flag < other.flag;
		return pos < other.pos;
	}
}x[maxd],y[maxd];
int posx[maxd*2],posy[maxd*2],ans;
int main(){
	int a,b,c,d,ant=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		x[ant].l=a , x[ant].r = c , x[ant].pos = b;
		y[ant].l=b , y[ant].r =d , y[ant++].pos = a;
		x[ant].l=a , x[ant].r = c, x[ant].pos = d , x[ant].flag=1;
		y[ant].l=b,y[ant].r = d, y[ant].pos = c , y[ant++].flag=1;
	}
	sort(x,x+ant);
	sort(y,y+ant);
	for(int i=0;i<ant;i++)
	{
	    if(x[i].flag)
			for(int j=x[i].l;j<x[i].r;j++)
				{
					posx[j+maxd]--;
					if(!posx[j+maxd]) ans++ ; 
				}
		else 
			for(int j=x[i].l;j<x[i].r;j++)
				{
					if(!posx[j+maxd]) ans++;
					posx[j+maxd]++;
				}
		if(y[i].flag)
			for(int j=y[i].l;j<y[i].r;j++)
				{
					posy[j+maxd]--;
					if(!posy[j+maxd]) ans++;
				}
		else 
			for(int j=y[i].l;j<y[i].r;j++)
				{
					if(!posy[j+maxd]) ans++;
					posy[j+maxd]++;
				}
	}
	printf("%d",ans);
	return 0;
}