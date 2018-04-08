#include <iostream>
using namespace std;
int arr[50];
void init(){
	arr[1]=1;
	arr[2]=2;
	for(int i=3;i<50;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
}
int main(){
	int number,x;
	cin >> number;
	init();
	while(number--){
		cin >> x ;
		cout << arr[x] << endl;
	}
	return 0;
}