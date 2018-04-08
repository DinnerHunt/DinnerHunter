//P1216 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
int n,arr[1005][1005],k,mx=0;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			cin >> k;
			arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + k;
			ma = max(arr[i][j],mx);
		}
	cout << ma;
	return 0;
}