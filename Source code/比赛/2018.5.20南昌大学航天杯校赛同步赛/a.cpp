#include <iostream>
using namespace std;
string str;
int main(){
	while(cin >> str)
	{
		for(int i=0;i<str.length();i++)
			if(str[i]>='a'&&str[i]<='z')
				printf("%c",str[i]-32);
			else if(str[i]>='A'&&str[i]<='Z')
				printf("%c",str[i]+32);
			else
			    printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}