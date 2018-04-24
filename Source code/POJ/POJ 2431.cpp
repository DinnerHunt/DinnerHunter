#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd = 10005;
priority_queue<int> que;
queue<int> k;
int arr[maxd];
int main(){
	int a,b,ans=0,n,last=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&arr[i],&a);
		k.push(a);
	}
	scanf("%d %d",&a,&b);
	for(int i=0;i<n;i++)
	{
		if(b>=arr[i]-last) b-=arr[i];
		else if(!que.empty())
        {
			do{
				b+=que.top();
				que.pop();
				ans++;
			}while(b<arr[i]-last);
			b-=arr[i]-last;
		}
		else
		{
			printf("-1");
			return 0;
		}
		last = arr[i];
		que.push(que.front());
		que.pop();
	}
	printf("%d",ans);
	return 0;
}