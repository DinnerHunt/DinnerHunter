#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int arr[200];
int main(){
	int n,m,s,ans=0,now,last;
	priority_queue<int> que;
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<s;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+s);
	last = arr[0];
	for(int i=1;i<s;i++){
		now = arr[i];
		que.push(now-last);
		ans+=now-last;
		last = now;
	}
	for(int i=1;i<n;i++)
	{
		if(que.empty()) break;
		ans-=que.top();
		que.pop();
	}
	if(s<n)
	printf("%d",s);
	else
	printf("%d",ans+n);
	return 0;
}