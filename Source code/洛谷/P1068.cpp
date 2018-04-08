//P1068 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int id,sum;
	bool operator < (const node &a) const{
		return sum > a.sum;
	}
}arr[5010];

int main(){
	int n,m,x,y;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		arr[i].sum=y;
		arr[i].id=x;
	}
	sort(arr+1,arr+n+1);
	m*=1.5;
	while(arr[m+1]==arr[m])m++;
	cout << arr[m] << m << endl;
	for(int i=1;i<=m;i++){
		cout << arr[i].id << " " << arr[i].sum << endl;
	}
	return 0;
}