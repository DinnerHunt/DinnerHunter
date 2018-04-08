//P1208 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int size,money;
	bool operator <(const node &a) const {
		return money > a.money;
	}
}arr[5050];
int main(){
	int m,n,ans=0;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i].money >> arr[i].size;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		int x=arr[i].size,y=arr[i].money;
		if(m<x){
			ans+= m*y;
			break;
		}
		else
		{
			ans+=x*y;
			m-=x;
		}
	}
	cout << ans;
	return 0;
		
}