//WERTYU UVa10082
#include <stdio.h>  

int main()  
{  
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";  //将键盘的值全部存入数组
	int i,c;			

    while((c=getchar()) !=EOF){  						//读取字符
	
        for (i = 1 ;s[i]&&s[i]!=c;i++ );				//循环，直到找到读取的字符的时候停下			
		if(s[i]) putchar(s[i-1]);						//如果不为空，则输出这个字符的前一个字符；
		else putchar(c);
    }  
	return 0; 
} 