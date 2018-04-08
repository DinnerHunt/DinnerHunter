#include <iostream>
#include <alorithm>
using namespace std;
int n,m,ans[50005],a[50005],len=1;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	ans[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>ans[len])
			ans[++len]=a[i];
		else{
			int pos = lower_bound(ans,ans+len,a[i])-ans;
			ans[pos] = a[i];
		}
	}
	cout << len;
	return 0;
}