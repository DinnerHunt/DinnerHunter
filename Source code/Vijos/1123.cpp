//Vijos 1123 均分纸牌
#include <cstdio>
using namespace std;

int main(){
	int number,arr[105],sum=0,count=0;
	scanf("%d",&number);
	for(int i=0;i<number;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sum/=number;
	for(int i=0;i<number-1;i++){
		if(arr[i]<sum){arr[i+1]-=sum-arr[i];count++;}
		if(arr[i]>sum){arr[i+1]+=arr[i]-sum;count++;}
	}
	printf("%d",count);
	return 0;
}