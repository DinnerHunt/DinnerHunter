#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 105;
int G[maxd][maxd],n;
int low[maxd],fpn[maxd],belong[maxd],ssc,number;
int que[maxd],top,ru,chu;
bool inq[maxd],r[maxd],c[maxd];
void tarjan(int x){
	low[x] = fpn[x] = ++number;
	que[top++] = x;
	inq[x] = true;
	for(int i=1;i<=n;i++)
		if(G[x][i])
		{
			if(!fpn[i])
			{
				tarjan(i);
				low[x] = min(low[x],low[i]);
			}
			else if(inq[i])
				low[x] = min(low[x],fpn[i]);
		}
	if(fpn[x] == low[x])
	{
		ssc++;
		do{
			belong[que[--top]] = ssc;
			inq[que[top]] = false;
		}while(que[top]!=x);
	}
}
int main(){
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		while(scanf("%d",&a)!=EOF&&a)
			G[i][a]=1;
	for(int i=1;i<=n;i++)
		if(!fpn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(belong[i]!=belong[j]&&G[i][j]){
				r[belong[j]] = true;
				c[belong[i]] = true;
			}
	for(int i=1;i<=ssc;i++)
	{
		if(!r[i]) ru++;
		if(!c[i]) chu++;
	}
	printf("%d\n%d",ru,ssc==1?0:max(ru,chu));
	return 0;
}