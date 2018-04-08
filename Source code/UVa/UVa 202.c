//循环小数 UVa202 
#include <stdio.h>
#include <string.h>

int main(){
	int x,y;
	while(scanf("%d %d"),&x,&y){
		int t=x,i=0;					//因为后面需要改变x的值，而最后需要输出x/y
		int arr1[y],arr2[y],arr3[y];		//arr1存储取余出现过的值，arr[2]存储每次的除数，arr[3]存储每轮的余数，用来判断循环位置
		arr2[i++]=x/y;
		x=x%y;
		while(!arr1[x]&&x){				//当余数没有出现过第二次时并且余数不为零时
			arr1[x]=i;					//出现过得余数的位置赋值，
			arr3[i]=x;					//把现在出现的余数赋值到arr3[i]
			arr2[i++]=x*10/y;			//存储除值
			x=x*10%y;
		}
		int j=1;
		printf("%d/%d = %d.",t,y,arr2[0]);
		for(j=1;j<i&&j<50;j++){			//循环输出各个位上的结果，
			if (n && s[i] == n) printf("(");  //如果碰到循环位的开始，则输出'('
            printf("%d",r[i]);  
		}
		if()
			printf("(0");
		if(count)
			printf("...");
		printf(")");
		printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);
			
	}
	return 0;
}