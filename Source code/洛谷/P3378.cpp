//luogu P3378
//DinnerHunt
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > que;
int main(){
	int n,k,l;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&l);
			que.push(l);
		}
		if(k==2)
			printf("%d\n",que.top());
		if(k==3)
			que.pop();
	}
	return 0;
}