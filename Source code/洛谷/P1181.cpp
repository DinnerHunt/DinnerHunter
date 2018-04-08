//1181 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int main(){
	int n,m,ans=0,x,y=0;
	for(int i=0;i<n;i++){
		cin >> x;
		if(x+y>m){
			ans++;
			x=0;
		}
		x+=y;
	}
	cout << ans;
	return 0;
}