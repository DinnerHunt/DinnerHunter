#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 
const int maxd = 1005;
int G[maxd][maxd];
int n,m,d[maxd],flag[maxd],eid,ans;
int dfs(int x)
{
	if(d[x] > 0) return d[x];
	d[x] = 1;
	for(int i=1;i<=n;i++)
		if(G[i][x])
			d[x] = max(d[x],dfs(i)+1);
	return d[x];
}
int main(){
	int a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{	
		scanf("%d",&a);
		vector<int> vet;
		memset(flag,0,sizeof(flag));
		for(int j=0;j<a;j++)
		{
			scanf("%d",&b);
			flag[b] = 1;
			vet.push_back(b);
		}
		for(int j=vet[0];j<=vet[vet.size()-1];j++)
			if(!flag[j])
				for(int k=0;k<vet.size();k++)
					G[j][vet[k]] = 1;
	}
	for(int i=1;i<=n;i++){
		if(!d[i]) d[i] = dfs(i);
		ans = max(ans,d[i]);
	}
	printf("%d",ans);
	return 0;
}