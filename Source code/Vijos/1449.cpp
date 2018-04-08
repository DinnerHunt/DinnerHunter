#include <stdio.h>
using namespace std;
const int maxn = 10000 + 10;
int main(){
	char a[maxn],b[maxn],c[maxn];
	int n,i;
	scanf("%d",&n);
	scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);

	if((a[0]+b[0]-2*c[n-1])%26==0)
		for(i=n-1;i>=0;i--)
			printf("%c",c[i]);
	
	else if((a[0]+c[0]-2*b[n-1])%26==0)
		for(i=n-1;i>=0;i--)
			printf("%c",b[i]);

	else 
		for(i=n-1;i>=0;i--)
			printf("%c",a[i]);

	return 0;
}