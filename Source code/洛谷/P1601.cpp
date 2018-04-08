//luogu P1601 A+B problem
//DinnerHunt
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string a,b;
void sw(string &str){
	int start=0,end=str.length()-1;
	char k;
	while(start<end)
	{
		k = str[start];
		str[start++] =str[end];
		str[end--] = k;
	}
}
void jia(const string &a,const string &b){
	string x = a,y = b,z="";
	sw(x);sw(y);
	int k=0,i=0;
	while((i<x.length()||i<y.length())||k)
	{
		int sum=0;
		if(i<x.length())
			sum += x[i]-'0';
		if(i<y.length())
			sum += y[i]-'0';
		sum+=k;
		z += sum%10 +'0';
		if(sum>=10) k=1;
		else k=0;
		i++;
	}
    sw(z);
    cout << z;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
    jia(a,b);
	return 0;
}