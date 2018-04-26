#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd =105;
int arr[maxd][maxd];
int main(){
	int t,n,a,b,c,d;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int ans=0;
		memset(arr,0,sizeof(arr));
		for(int j=0;j<n;j++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			for(int i=a;i<c;i++)
				for(int j=b;j<d;j++)
					arr[i][j] +=1;
		}
		for(int i=0;i<=100;i++)
			for(int j=0;j<=100;j++)
				ans = max(arr[i][j],ans);
		printf("%d\n",ans);
	}
	return 0;
}