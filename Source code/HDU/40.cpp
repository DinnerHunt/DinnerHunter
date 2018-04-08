#include <iostream>
using namespace std;
int nace(int x){
	int sum=1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			sum+=i;
			sum+=x/i;
		}
	}
	return sum;
}
int main{
	int number,x,y;
	cin >> number;
	while(number--){
		cin >> x >> y;
		if(nace)==y
			cout << "YES" <<endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}