#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 1005;
char str1[maxd],str2[maxd];
int arr[maxd][maxd];
int same(int x,int y){
	if(str[x]==str[y])
		return 0;
	return 1;
}
int main(){
	scanf("%s %s",&str1,&str2);
	int len = max(strlen(str1),strlen(str2));
	for(int i=1;i<=len;i++)
	{
		 arr[0][i] = i;
		 arr[i][0] = i;
	}
	for(int i=1;i<=strlen(str1);i++)
		for(int j=1;j<=strlen(str2);j++)
			arr[i][j] = min(arr[i-1][j-1]+same(i,j),min(arr[i][j-1],arr[i-1][j])+1);
	printf("%d",arr[strlen(str1)][strlen(str2)]);
	return 0;
}