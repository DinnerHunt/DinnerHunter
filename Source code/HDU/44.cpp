#include <iostream>
using namespace std;
int fb(int x){
	if(x==1)
		return 1;
	else if(x==2)
		return 2;
	else
		return fb(x-1)+fb(x-2);
}
int main(){
	int number,x,y;
	cin >> number;
	while(number--){
		cin >> x >> y;
		cout << fb(y-x)  << endl;
	}
	return 0;
}