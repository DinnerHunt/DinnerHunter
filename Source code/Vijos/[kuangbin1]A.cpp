//kuangbin one A
//棋盘问题
#include <cstdio>
#include <cstring>
using namespace std;
int flag[10],arr[10][10],n,m,k;
void dfs(int x){
	if(x==n)
		k++;
	else
		for(int i = 0;i<n;){



		}

}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF&&n!=-1&&m!=-1){
		memset(arr,-1,sizeof(arr));
		k=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%c",&arr[i][j]);
		dfs(0);
		printf("%d\n",k);

	}
	return 0;
}
