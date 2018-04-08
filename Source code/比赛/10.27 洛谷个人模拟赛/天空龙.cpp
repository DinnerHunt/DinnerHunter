#include<iostream>
using namespace std;
bool pd(int a,int b,int c,int x,int y,int z){
	int a1=a-x,b1=b-y,c1=c-z;
	if(a1>0) a1/=2;
	if(b1>0) b1/=2;
	if(c1>0) c1/=2;
	cout << a1 << " " << b1 << " " << c1 << " " << endl;
	return a1+b1+c1>0;
}
int main(){
	int n,a,b,c,x,y,z;
	cin >> n;
	while(n--){
		cin >> a >> b >> c >> x >>y >> z;
		if(pd(a,b,c,x,y,z))
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}