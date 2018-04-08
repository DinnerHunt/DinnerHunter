//周期串 UVa455 2017.6.22
#include <stdio.h>
#include <string.h>
char arr[85];
int main(){
	int x;
	scanf("%d",&x);							//读取数据次数
	while(x--){								//
		int i,k;				
		scanf("%s",arr);					//读取数据
		int len=strlen(arr);				//获取长度
		for(k,i=1;i<=len;i++)				//周期从1开始遍历 如果全部字母相同则为1
			if(len%i==0){					//如果arr可以被当前数整除，说明可能是周期数
				for(k=i;k<len;k++)			//枚举arr中的每个数
					if(arr[k]!=arr[k%i])	//如果后面的数，与前面的前i个不服，则退出循环
						break;
				if(k==len){					//如果结尾是自动退出的，则说明这个周期是对的
					printf("%d\n",i);
					break;
				}
			
			}
		if (x) printf("\n");  
	}
	return 0;
}