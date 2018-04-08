//Vijos 1097 合并果子
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 10000+10;
int main(){
	int number,n,sum=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	scanf("%d",&number);
	for(int i=0;i<number;i++){
		scanf("%d",&n);
		qp.push(n);
	}
	while(!pq.empty()){
		int a=pq.top(); pq.pop();
		if(pq.empty())
			break;
		int b=pq.top(); pq.pop();
		sum=sum+a+b;
		pq.push(a+b);
	}
	printf("%d",sum);

	return 0;
}