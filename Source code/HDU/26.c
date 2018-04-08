#include <stdio.h>
#include <ctype.h>
int main(){
	int space=0;
	char ch;
	while(scanf("%c",&ch)!=EOF){
		if(ch=='\n'){
			printf("\n");
			space=0;
		}
		else if(ch==' '){
			printf(" ");
			space=0;
		}
		else if(!space){
			printf("%c",toupper(ch));
			space++;
		}
		else{
			printf("%c",ch);
			space++;
		}
	}
	return 0;
}