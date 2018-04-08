//P1115 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
const int INF= -1000000;
int main(){
	ios::sync_with_stdio(false);
	int mx=INF,n,m,k=INF;
	cin >> n;
	while(n--){
		cin >> m;
		k = max(m,k+m);
		mx = max(mx,k);
	}
	cout << mx;
	return 0;
}