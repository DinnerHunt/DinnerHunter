#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 1005;
char str1[maxd],str2[maxd];
int arr[maxd][maxd];
int main(){
	scanf("%s %s",str1,str2);
	for(int i=1;i<=strlen(str1);i++)
		for(int j=1;j<=strlen(str2);j++)
		{
			if(str1[i]==str2[j]) arr[i][j] = arr[i-1][j-1]+1;
			else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
		}
	printf("%d",arr[strlen(str1)][strlen(str2)]);
	return 0;
}