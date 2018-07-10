#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = 0x3fffffff;
const int maxd = 50005;

int dp[2][105];
int q[105];
int main(){
	int n,c,cur=1,nowf=0;
	scanf("%d %d",&n,&c);
	int res = inf;
	int tail,head,x;
	scanf("%d",&x);
	memset(q,0,sizeof(q));
	for(int j=1;j<x;j++)
		dp[0][j] = inf;
	for(int j=x;j<=100;j++)
		dp[0][j] = (x-j)*(x-j);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		tail = head = 0;
		for(j=1;j<=100;j++)
		{
			nowf = dp[cur^1][j]-c*j;
			while(nowf<q[tail-1]&&head < tail)
				tail--;
			q[tail++] = nowf;
			if(j<x) dp[cur][j] = inf;
			else dp[cur][j] = q[head]+c*j + (j-x)*(j-x);
		}
		tail = head = 0;
		for(j=100;j>=1;j--)
		{
			nowf =  d[cur^1][j]+c*j;
			while(nowf<q[tail-1] && head < tail)
				tail--;
			q[tail++] = nowf;
			if(j>=x)
				dp[cur][j] = min(dp[cur][j],q[head]-c*j+(j-x)*(j-x));
		}
	}	
	for(int j=1;j<=100;j++)
		res = min(res,dp[cur^1][j]);
	printf("%d\n",res);
	return 0;
}