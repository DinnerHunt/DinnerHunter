#include <iostream>
using namespace std;
int arr[55];
void init(){
	arr[1]=3;
	arr[2]=6;
	arr[3]=6;
	for(int i=4;i<55;i++)
		arr[i]=arr[i-1]+arr[i-2]*2;
}
int main(){
	init();
	int x;
	while(cin >> x)
		cout << arr[x] << endl;
	return 0;
}