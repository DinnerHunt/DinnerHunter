//Vjios 1848 计数问题
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int x,y,count=0;
	cin >> x >> y;
	for(int i=1;i<=x;i++){
		int z=i;
		while(z) {if(z%10==y)count++;z/=10;}
	}
	cout << count;
	return 0;
}