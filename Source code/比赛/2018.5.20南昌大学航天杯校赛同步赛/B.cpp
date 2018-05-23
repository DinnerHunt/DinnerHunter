#include <cstdio>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	if( (n+m)%2)
		printf("win");
	else
		printf("lose");
	return 0;
}