#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
int main()  
{  
    char a[100005];  
    int t,i,j,len,n1,n2,n3,n4,n5;  
    scanf("%d",&t);  
    getchar();  
    for(j=0;j<=t-1;j++)  
    {  
        n1=n2=n3=n4=n5=0;  
        gets(a);  
        len=strlen(a);  
        for(i=0;i<len;i++)  
        {  
            if(a[i]=='a') n1++;  
            if(a[i]=='e') n2++;  
            if(a[i]=='i') n3++;  
            if(a[i]=='o') n4++;  
            if(a[i]=='u') n5++;  
        }  
        printf("a:%d\n",n1);  
        printf("e:%d\n",n2);  
        printf("i:%d\n",n3);  
        printf("o:%d\n",n4);  
        printf("u:%d\n",n5);  
        if(j<t-1) printf("\n");  
    }  
    return 0;  
}  

