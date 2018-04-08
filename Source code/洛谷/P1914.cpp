#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	char x;
	while(cin >> x )
		cout << char((x-'a'+n)%26+'a');
	return 0;
}