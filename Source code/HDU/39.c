#include <iostream>
using namespace std;
int main(){
	int a,b,c,number;
	cin>>number;
	while(number--){
		cin >> a >> b >> c;
		if(a+b>c&&a+c>b&&c+b>a)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	return 0;
}
