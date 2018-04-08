//luogu P2661
//DinnerHunt
#include <iostream>
#include <cstring>
using namespace std;
int s[10];
void pd(int x){
	memset(s,0,sizeof(s));
	int y = x*2;
	int z = x*3;
	s[x%10] = 1;
	s[x/100] = 1;
	s[x/10%10] = 1;
	s[y%10] = 1;
	s[y/100] = 1;
	s[y/10%10] = 1;
	s[z%10] = 1;
	s[z/100] = 1;
	s[z/10%10] = 1;
	int flag=1;
	for(int i=1;i<=9;i++){
		if(!a[i]) flag=0;
	}
	if(flag) cout << x << " " << y <<" " << z << endl; 
}
int main(){
	for(int i=123;i<333;i++){
		pd(i);
	}
	return 0;
}