//luogu P1089
//DinnerHunt
#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n=0,k,sum=0;
	for(int i=1;i<=12;i++){
		cin >> k;
		if(300+n<k){cout << "-" << i;return 0;}
		sum+=(300+n-k)/100;
		n=(300+n-k)%100;
	}
	cout << n+sum*120 ;
	return 0;
}