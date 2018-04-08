#include <cstdio>
using namespace std;
void check(int x){
	int a = x/100;
	int b = x/10%1000;
	int c = x%1000;
	if(!(x%a)&&!(x%b)&&!(x%c)) printf("%d\n",x);
}
int main(){
	int n,i=0;
	scanf("%d",&n);
	while(i<10000)i+=n;
	for(;i<=30000;i+=n){
		check(i);
	}
	return 0;
}