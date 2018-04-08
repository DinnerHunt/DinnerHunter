#include <iostream>
#include <string>
using namespace std;
bool isAQ(string str){
	bool flag=false;
	int  x=0,y=0,z=0,h=0;
	for(int i=0;i<str.length();i++){
		if(str[i]>='a'&&str[i]<='z')
			x=1;
		else if(str[i]>='a'&&str[i]<='z')
			y=1;
		else if(str[i]>='0'&&str[i]<='9')
			z=1;
		else if(str[i] == '~' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^')
			h=1;
	}
	if(x+y+z+h>=3&&str.length()>=8&&str.length()<=16)
		flag=true;
	return flag;
}
int main(){
	int number;
	string str;
    cin >> number;
	while(number--){
		cin >> str;
		if(isAQ(str))
			cout << "YES" <<endl;
		else 
			cout << "NO" <<endl;
	}
	return 0;
}