//UVa 725
//Division 除法
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
int n,flag=1,arr[10];
int check(int x,int y){
	memset(arr,0,sizeof(arr));
	if(x<10000) arr[0]++;
	if(y<10000) arr[0]++;
	if(arr[0]>1) return 0;
	while(x){
		if(arr[x%10])
			return 0;
		arr[x%10]++;
		x/=10;
	}
	while(y){
		if(arr[y%10])
			return 0;
		arr[y%10]++;
		y/=10;
	}
	flag =0;
	return 1;
}
int main(){
    int count=0;
	while(scanf("%d",&n)&&n){
	    if(count++) printf("\n");
		flag = 1;
		for(int i=1234;i*n<100000;i++)
			if(check(i,i*n))
				printf("%d / %05d = %d\n",i*n,i,n);
		if(flag)
		printf("There are no solutions for %d.\n",n);
	}
	return 0;
}