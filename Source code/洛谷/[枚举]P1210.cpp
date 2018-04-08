#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string str = "";
string s;
int ans=0;
void check(int x,int y){
	int len=y-x+1;
	int a = x,b=y;
	while(x<y){
		while(!isalpha(str[x])){x++;len--;}
		while(!isalpha(str[y])){y--;len--;}
		if(x>y) break;
		if(!(str[x]==str[y]||str[x]+32==str[y]||str[x]==str[y]+32)){
			return;
		}
		x++;y--;
	}
	if(ans<len)
	{
		ans = len;
		s = str.substr(a,b-a+1);
	}
}int main(){
	char ch;
	while(scanf("%c",&ch)!=EOF)
		    str+=ch;
	
	int len = str.length();
	for(int i=0;i<len;i++)
		if(isalpha(str[i]))
		for(int j=len-1;j>i;j--){
			if(str[i]==str[j]||str[i]+32==str[j]||str[i]==str[j]+32)
				check(i,j);
		}
	cout << ans << endl << s;
	return 0;
}	