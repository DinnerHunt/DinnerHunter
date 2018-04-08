//UVa 11059
//Maximun Product 最大乘积
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[20];
int n,flag=0;
long long check(){
	long long k=0,now;
	for(int i=1;i<=n;i++){
		now=1;
		for(int j=i;j<=n;j++){
			now*=arr[j];
            k=max(k,now);
        }
	}
	return k;
}
int main(){
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;i++)
			cin >> arr[i];
		printf("Case #%d: The maximum product is %lld.\n\n",++flag,check());
	}
	return 0;
}