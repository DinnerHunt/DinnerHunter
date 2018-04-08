//Tex中的引号 UVa272 
#include<stdio.h>
int main(){
	char x;
	int y=1;
	while(scanf("%c",&x)==1){
		if(c=='"'){
			printf("%s",y?"``":"''");
			y=!y;
		}
		else
			printf("%c",x);
	}
	return 0;
}