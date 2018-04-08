//P1200 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int main(){
	string a,b;
	int x=1,y=1;
	cin >> a >> b;
	for(int i=0;i<a.length();i++){
		x*=a[i]-'A';
		if(x>100)
			x%=47;
	}
	for(int i=0;i<b.length();i++){
		y*=b[i]-'A';
		if(y>100)
			y%=47;
	}
	if(x==y)
		cout << "GO";
	else
		cout << "STAY";
	return 0;
}