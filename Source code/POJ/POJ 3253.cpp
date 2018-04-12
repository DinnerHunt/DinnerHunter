//POJ 3253
//DinnerHunt
#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int n,k;
    while(scanf("%d",&n)==1)
    {
    	long long ans;
		priority_queue<int,vector<int>,greater<int> >que;
		while(n--)
		{
			scanf("%d",&k);
			que.push(k);
		}
		while(que.size()>=2)
		{
			long long a = que.top() ; que.pop();
			long long b = que.top() ; que.pop();
			que.push(a+b);
			ans+=a+b;
		}
		printf("%lld",ans);
	}
	return 0;
}