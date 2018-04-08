//P1280 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<long int,long int> P;
P arr[10005];
long int sum[10001],num=1,f[10001];
int cmp(P &a,P &b)
{
	return a.first > b.first;
}
int main(){
	long int t,k,a,b;
	cin >> t >> k;
	for(int i=1;i<=k;i++){
		cin >> a >> b;
		arr[i]=P(a,b);
		sum[a]++;
	}
	sort(arr+1,arr+k+1,cmp);
	for(int i=n;i>=1;i--){
		if(!sum[i]) f[i] = f[i+1]+1;
		else for(j=1;j<=sum[i];j++)
		{
			if((f[i+arr[num].second]>f[i]))
				f[i] = f[i+z[num].second];
			num++;
		}
	}
	cout << f[1];
	return 0;
}