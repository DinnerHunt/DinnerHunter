#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd = 505;
int arr[maxd][maxd],n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	
			if(!i&&!j)continue;
			if(!i)arr[i][j]=arr[i][j-1]+arr[i][j];
			else if(!j)arr[i][j]=arr[i-1][j]+arr[i][j];
			else arr[i][j] = max(arr[i-1][j]+arr[i][j],arr[i][j-1]+arr[i][j]);
		}
	printf("%d",arr[n-1][n-1]);
	return 0;
}