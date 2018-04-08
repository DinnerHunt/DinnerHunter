#include <iostream>
#include <cstdio>
using namespace std;
int a[100010],b[100010],g[100010],k[100010];
int main(){
	int number,x,y,env=0;
	cin >> number;
	for(int i=0;i<number;i++){
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	cin >> x >> y;
	for(int i=number-1;i>=0;i--){
		if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]){
			cout << i+1;
			env = i+1;
			break;
		}
	}
	if(!env)
		cout << "-1";

	return 0;
}