#include <cstdio>
using namespace std;
int f[6] = {0,0,1,2,4,5};
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(f<=5) printf("%d\n",f[n]);
		else
			printf("%d",n+((n-5)*n)/2);
	}
	return 0;
}