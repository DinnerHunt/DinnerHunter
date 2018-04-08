#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node{		
	int id,len;
	string str;
	bool operator < (const node &a)const {
		if(len == a.len){
			return str > a.str;
		}
		else 
			return len > a.len;
	}
}arr[25];
int main(){
	int number;
	cin >> number;
	for(int i=1;i<=number;i++){
		cin >> arr[i].str;
		arr[i].id=i;
		arr[i].len=arr[i].str.length();
	}
	sort(arr+1,arr+number+1);
	cout << arr[1].id<<endl;
	cout << arr[1].str;
	return 0;
}