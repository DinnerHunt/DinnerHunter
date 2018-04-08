#include <stdio.h>
#include <ctype.h>
int main(){
	int number;
	scanf("%d",&number);
	getchar();
	while(number--){
		int sum=0;
		char ch;
		while(scanf("%c",&ch)!=EOF&&ch!='\n'){
			if(isdigit(ch))
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}