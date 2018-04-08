//P1031 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int main(){
	int n,arr[105],sum=0,env=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= n;
	for(int i=0;i<n;i++){
		if(arr[i]<sum){arr[i+1]-=sum-arr[i];env++;}
		if(arr[i]>sum){arr[i+1]+=arr[i]-sum;env++;}
	}
	cout << env;
	return 0;
}