#include <stdio.h>  
#include <string.h>  
void detom(int a, int *ma, int m)  
{  
    int i = 0;  
    while (a)  
    {  
        ma[i++] = a%m;  
        a /= m;  
    }  
}  
int main()  
{  
    int a, r, ma[40], flag, i;  
    while(~scanf("%d%d", &a, &r))  
    {  
        flag = 0;  
        memset(ma, 0, sizeof(ma));  
        if(a < 0)  
        {  
            a *= -1;  
            flag = 1;  
        }  
        detom(a, ma, r);  
        i = 39;  
        while(ma[i] == 0) i--;  
        if(i < 0)  
            printf("0\n");  
        else  
        {  
            if(flag)  
                printf("-");  
            while (i >= 0)   
            {  
                if(ma[i] < 10)  
                    printf("%d", ma[i]);  
                else  
                    printf("%c", ma[i] - 10 + 'A');  
                i--;  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  