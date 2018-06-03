#include <cstdio>
using namespace std;
int main(){
	long long result=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        result*=i;
        while(result%10==0)
            result/=10;
        result=result%100000000;
    }
    printf("%d",result%10);
	return 0;
}