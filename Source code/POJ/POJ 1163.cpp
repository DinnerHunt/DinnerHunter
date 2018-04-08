//POJ 1163 The Triangle
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100+5;
int n,arr[maxn][maxn];
int *mx;

int main(){
	while(cin >> n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin >> arr[i][j];
		mx = arr[n];
		for(int i=n-1;i>0;i--)
			for(int j=1;j<=i;j++){
				mx[j] = max(mx[j],mx[j+1])+arr[i][j];
			}

		cout << mx[1] << endl;
	}
	return 0;
}