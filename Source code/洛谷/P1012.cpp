//P1012 luogu
//DinnerHunt
#include <iostream>
using namespace std;
bool cmp(string x,string y){
	return x<y;
}
int main(){
	int n;
	cin >> n;
	string arr[25];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		cout << arr[i]; 
	return 0;
}