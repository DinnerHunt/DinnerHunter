#include <cstdio>
#include <queue>
using namespace std;
const int maxd = 20005;
int m,n,f[maxd],per[maxd];
int gf(int x)
{
	if(f[x] == x) return x;
	return f[x] =  gf(f[x]);
}
void until(int x,int y)
{
	f[gf(x)] = gf(y);
}
struct node{
	int x,y,z;
	bool operator < (const node &other) const {
		return z < other.z;
	}
};
priority_queue<node> que;
int main(){
	int a,b,c,i;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++) f[i] = i;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		que.push(node{a,b,c});
	}
	for(i=0;i<n;i++)
	{
		node nod = que.top();
		que.pop();
		if(gf(nod.x) == gf(nod.y)){ 
			printf("%d",nod.z); 
			return 0;
		}
		if(!per[nod.x]) per[nod.x] = nod.y;
		else until(per[nod.x],nod.y);
		if(!per[nod.y]) per[nod.y] = nod.x;
		else until(per[nod.y],nod.x);
	}
	printf("0");
	return 0;
}