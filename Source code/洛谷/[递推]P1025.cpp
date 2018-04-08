//P1025 luogu
//DinnerHunt
#include<iostream>
using namespace std;
int arr[205][7];
int f(int m,int n){
    if(arr[m][n]) return arr[m][n];
    if(n>m) return 0;
	if(!m) return 1;
	if(!n) return 0;
	return arr[m][n]=f(m-1,n-1)+f(m-n,n);
}
int main(){
	ios::sync_with_stdio(false);
	int x,y;
	cin >> x >> y;
	cout <<f(x,y);
	return 0;
}