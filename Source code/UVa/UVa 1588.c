//换低档装置 UVa1588 2017.6.26
#include <stdio.h>
#include <string.h>
#define max 205
char arr1[max];									//储存第一个数
char arr2[max];									//储存第二个数
int main(){										
	while(scanf("%s %s",arr1,arr2)==2){
		int i=0,j=0,k=0,len1=strlen(arr1),len2=strlen(arr2);
		int count1,count2;						//因为有两种可能，第一条在前，或者第二条在前，所以得把两种结果都写出来
												//最低长度=arr1的长度+arr2的长度- 共同部分的长度
		while(j<len1&&i<len2)  					//当arr1在前面时，重叠部分为i在arr1的区域
        {  
            if(arr1[j]+arr2[i]-96<=3)  			//如果当前节相加没有超过3的时候，则判断下一节
            {  
                i++,j++;  
            }  
            else  								//不然，则从下一节开始判断是否超过3
                k++,i=0,j=k;  
        }  
		count1 =len1+len2-i;
		i=j=k=0;
								
		while(j<len2&&i<len1)  					//反过来考虑第二种情况
        {  
            if(arr2[j]+arr1[i]-96<=3)  
            {  
                i++,j++;  
            }  
            else  
                k++,i=0,j=k;  
        } 
		
		count2 = len1+len2-i;					
        printf("%d\n",count1 < count2 ? count1 : count2 );  
	}
	return 0;
}