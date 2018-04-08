#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10],b[10],n,m,k,pos;
typedef pair<int,int> P;
P c[100];
char ch;
void dfs(int x,int y){ 	// x搜到第几个位置，y摆了几个棋
	if(x==pos||y==m){
		if(y==m)
			k++;
	}
	else{
		if(a[c[x].first]==-1&&b[c[x].second]==-1){
			a[c[x].first]=1;
			b[c[x].second]=1;
			dfs(x+1,y+1);
			a[c[x].first]=-1;
			b[c[x].second]=-1;
		}
		dfs(x+1,y);
	}
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF&&n!=-1&&m!=-1){
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		k=0,pos=0;
        ch = getchar();
		for(int i=0;i<n;i++)
			for(int j=0;j<=n;j++)
			{
				scanf("%c",&ch);
				if(ch=='#')
					c[pos++] = P(i,j);
			}
		dfs(0,0);
		printf("%d\n",k);
	}
	return 0;
}