#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string arr[25];
int flag[25];
int number;
int nowlen=0,maxlen=0;
int pipei(string &str1,string &str2){
	if(str1.length()==1){
		if(str1[0]==str2[0])return str2.length();
		return 0;
	}
	for(int i=1;i<str1.length();i++){
		string temp1 = str1.substr(str1.length()-i);
		string temp2 = str2.substr(0,i);
		if(temp1==temp2) return str2.length()-i;
	}
	return 0;
}
void dfs(string str){
	for(int i=1;i<=number;i++){
        
		int temp = pipei(str,arr[i]);
		if(temp&&flag[i]<2){
			flag[i]++;
			nowlen+=temp;
			maxlen = max(maxlen,nowlen);
			dfs(arr[i]);
			nowlen-=temp;
			flag[i]--;
		}
	}
}
int main(){
	string str;
	cin >> number;
	for(int i=1;i<=number;i++) cin >> arr[i];
	cin >> str;
	dfs(str);
	cout << maxlen;
	return 0;
}