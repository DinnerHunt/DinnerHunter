#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 10005;
typedef pair<int,int> P;
P arr[maxd];
bool cmp(P a,P b){
	return a.second < b.second;
}
int main(){
	int n,ans=1;
	priority_queue<P,vector<P>,greater<P> >que;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&arr[i].second,&arr[i].first);
	sort(arr,arr+n,cmp);
	que.push(P(arr[0]));
	for(int i=1;i<n;i++)
	{
		if(arr[i].second < que.top().first)
		{
			que.push(P(arr[i]));
			ans++;
		}
		else
		{
			que.pop();
			que.push(P(arr[i]));
		}
	}
	printf("%d",ans);
	return 0;
}