//P1803 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int begin,end;
	bool operator < (const node &a) const{
		return end < a.end;
	}
}arr[1000100];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i].begin >> arr[i].end;
	}
	sort(arr+1,arr+1+n);
	int ans=0,now=0;
	for(int i=1;i<=n;i++){
		if(now <= arr[i].begin){
			now = arr[i].end;
			ans++;
		}
	}
	cout << ans;
	return 0;
}