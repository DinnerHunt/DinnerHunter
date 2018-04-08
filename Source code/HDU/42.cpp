#include <iostream>
using namespace std;
int main(){
	int number,x;
	cin >> number ;
	while(number--){
		cin >> x;
		int sum=3;
		for(int i=0;i<x;i++){
			sum=sum*2-2;
		}
		cin << sum << endl;
	}
	return 0;
}