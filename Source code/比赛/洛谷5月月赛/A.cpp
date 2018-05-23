#include <cstdio>
using namespace std;
const int maxd = 105;
typedef long long LL;
LL ans,a; 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a);
		ans += a;
	}
	if(ans % 2 == 1)
		printf("Alice");
	else
		printf("Bob");
	return 0;
}