//P1206 回文平方数
//DinnerHunt
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,k;
string str,str1;
char arr[22]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
bool check(int x){
	str.clear();
    str1.clear();
	int y = x*x;
	do{
		str+=arr[y%n];
		y/=n;		
	}while(y);
	int len = str.length();
	for(int i=0;i<=len/2;i++){
		if(str[i]!=str[len-i-1])
			return false;
	}
	do{
		str1=arr[x%n]+str1;
		x/=n;
	}while(x);
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=1;i<=300;i++){
		if(check(i))
			cout << str1 << " " << str << endl;
	}
	return 0;
}