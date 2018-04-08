#include <stdio.h>
#include <string.h>
char arr[105];
int main(){
	while(gets(arr)!=EOF){
		char big='0';
		for(int i=0;i<strlen(arr);i++){
			if(arr[i]>big)
				big=arr[i];
		}
		for(int i=0;i<strlen(arr);i++){
			printf("%c",arr[i]);
			if(arr[i]==big)
				printf("(max)");
		}
		printf("\n");

	}
	return 0;
}