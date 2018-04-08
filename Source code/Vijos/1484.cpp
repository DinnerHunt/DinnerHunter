//vijos 1484 ISBN号码
#include <cstdio>
#include <cctype>
using namespace std;
int main(){
	char arr[11],str[13];
	for(int i=0;i<10;i++)
		arr[i] = i+'0';
	arr[10]='X';
	int i=0,sum=0,j;
	scanf("%s",str);
	for(i=0,j=1;i<=10;i++){
		if(isdigit(str[i]))
			sum += (str[i]-'0')*j++;
	}
	sum%=11;
	if(str[12]==arr[sum%11])
		printf("Right");
	else{
		str[12] = arr[sum%11];
		printf("%s",str);
	}
	return 0;
}