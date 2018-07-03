#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 100005;
int arr[maxd];
int pt[maxd][55];
int n,k;
void init(){
	for(int i=0;i< n+10; i++)
	{
		pt[i][0] = 1;
		for(int j = 1; j,=55;j++)
			pt[i][j] = (pt[i-1][j] + pt[i-1][j-1]) %mod;
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	init();
	long long sum = 0;
	
	return 0;
}