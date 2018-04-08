//P1029 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int gcd(int x,int y){
	if(x%y==0) return y;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	int x0,y0;
	cin >> x0 >> y0;
	int a=x0*y0,ans=0;
	for(int p=1,q;p<=a;p++)
	{
		if(a%p!=0)continue;
		q=a/p;
		if(gcd(p,q)==x0) ans++;
	}
	cout << ans;
	return 0;
}