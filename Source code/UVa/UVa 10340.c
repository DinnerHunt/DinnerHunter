//згађСа UVa202 2017.6.25
#include <stdio.h>
#include <string.h>
#define max 100005
char arr1[max];
char arr2[max];
int main(){
    while(scanf("%s %s",arr1,arr2)==2){
        int list1=strlen(arr1);
		int list2=strlen(arr2);
		if(list1>list2){
			printf("No\n");
			continue;
		}
		
		int i,j=0;
        for(i=0;i<list2;i++)
            if(arr2[i]==arr1[j]&&j++==list1-1)
				break;
  
        if(j==list1)
			printf("Yes\n");
		else 
			printf("No\n");
    
    }
	return 0;
}