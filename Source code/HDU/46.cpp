#include <iostream>
using namespace std;
long long arr[55];
void init(){
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	for(int i=4;i<55;i++)
		arr[i]=arr[i-1]+arr[i-2];
}
int main(){
	int x ;
	while(cin >> x)
		cout << arr[x] << endl;
	return 0;
}