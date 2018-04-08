//UVa Ordering Tasks 给任务排序
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int arr[105],G[105][105];
void topu(){
	queue<int> que;
	int flag = 0;
	for(int i=1;i<=n;i++)
		if(!arr[i])
			que.push(i);
	while(!que.empty()){
		int k = que.front();
		que.pop();
		if(flag++) printf(" "); 
		printf("%d",k);
		for(int i=1;i<=n;i++)
			if(G[k][i]){
				arr[i]--;
				if(!arr[i])
					que.push(i);
			}
	}
}
int main(){
	int x,y,flag=0;
	while(scanf("%d %d",&n,&m)&&(n||m)){
		memset(arr,0,sizeof(arr));
		memset(G,0,sizeof(G));
		while(m--){
			scanf("%d %d",&x,&y);
            if(!G[x][y]){
			    G[x][y]=1;
			    arr[y]++;
            }
		}
		topu();
		printf("\n");
	}
	return 0;
}