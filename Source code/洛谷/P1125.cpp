#include <iostream>
#include <algorithm>
using namespace std;
int arr[26];
bool isZhs(int ans){
	if(ans == 0||ans == 1)
		return false;
	if(ans == 2||ans == 3)
		return true;
	for(int i=2;i*i<=ans;i++){
		if(ans%i==0)
			return false;
	}
	return true;
}
int main(){
	string str;
	cin >> str;
	memset(arr,0,sizeof(arr));
	for(int i=0;i<str.length();i++)
		arr[str[i]-'a']++;
	int maxn=arr[0],minn=100000;
	for(int i=0;i<26;i++)
	{
		if(!arr[i]){
			maxn=max(maxn,arr[i]);
			minn=min(minn,arr[i]);
		}
	}
	int env = maxn - minn;
	if(isZhs(env))
		cout << "Lucky Word" << endl << env;
	else
		cout << "No Answer" << endl << env;
	return 0;
}