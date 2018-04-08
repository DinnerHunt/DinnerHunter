#include <iostream>
#include <algorithm>
using namespace std;
int arr[30010];
int main(){
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+m+1);
	int left=1,right=m;
	while(left<=right){
		if(arr[left]+arr[right]<=n)
		{
			ans++;
			left++;
			right--;
		}
		else
		{
			right--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}