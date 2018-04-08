//UVa 10410
//树重建 Tree Reconstruction
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1005;
vector<int> vet[maxn];
stack<int> stk;
int n,root,k,t;
int pos[maxn];
void init(){
	for(int i=1;i<=n;i++)
		vet[i].clear();
	while(!stk.empty())
		stk.pop();
}
int main(){
	while(scanf("%d",&n)==1&&n){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			pos[k] = i;
		}
		scanf("%d",&root);
		stk.push(root);
		for(int i=2;i<=n;i++){
			scanf("%d",&t);
			while(1){
				k = stk.top();
				if( pos[k]+1 < pos[t] || (pos[k]+1==pos[t]&&k>t) || k == root)  // 判断t是否是k的子节点 
				{
					vet[k].push_back(t);
					stk.push(t);
					break;
				}
				stk.pop();
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d:",i);
			for(int j=0;j<vet[i].size();j++)
				printf(" %d",vet[i][j]);
			printf("\n");
		}
	}
	return 0;
}