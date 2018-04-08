#include <iostream>
#include <cstring>
using namespace std;
char str1[3][7];
char str2[3][7];
char str3[3][7];
string str1[3],str2[3],str3[3];
bool pd(char i,bool flag){
	for(int i=0;i<3;i++){
		char *a,*b;
		if(flag){
			a=str1[i];
			b=str2[i];
		}
		else
		{
			a=str2[i];
			b=str1[i];
		}
		switch(str3[i][0])
		{
			case 'u':
				if(strchr(b,i)==NULL)
					return false;
				break;

			case 'e':
				if(strchr(b,i)||strchr(a,i))
					return false;
				break;

			case 'd':
				if(strchr(a,i)==NULL)
					return false;
				break;
		}
	}
}
int main(){
	int n;
	cin >> n;
	while(t--){
		for(int i=0;i<3;i++)
			cin >> str1[i] >> str2[i] >> str3[i];
		for(char i='A';i<='Z';i++)
		{
			if(pd(i,true)){
				cout << i <<" is the counterfeit coin and it is light.";
			}
			else if(pd(i,false)){
				cout << i <<" is the counterfeit coin and it is heavy.";
			}
		}
	}
	return 0;
}