//UVa 10976
//Fractions Again?!
//DinnerHunt
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	int n,k;
	vector<int> a,b;
	while(scanf("%d",&n)==1){
		k=0;
		for(int i=n+1;i<=2*n;i++)
			if(n*i%(i-n)==0){
				a.push_back(n*i/(i-n)),b.push_back(i);
			}
		printf("%d\n",k);
		for(int i=0;i<k;i++)
			printf("1/%d = 1/%d + 1/%d\n",n,a[i],b[i]);
	}
	return 0;
}
