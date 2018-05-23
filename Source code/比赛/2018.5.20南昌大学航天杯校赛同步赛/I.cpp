#include <cstdio>
using namespace std;
long long a,b,ans;
int main(){
	while(scanf("%lld %lld",&a,&b)!=EOF){
	    ans = b-a;
		printf("%02lld:%02d:%02d\n",ans/3600,ans/60%60,ans%60);
	}
	return 0;
}