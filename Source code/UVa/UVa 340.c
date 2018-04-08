//猜数字游戏的提示 UVa 340

#include <stdio.h>
#define maxn 1010
int main(){
	int n,a[maxn],b[maxn];			//存放正确值和猜测值
	int kase =0;					//输出每组数据的标识
	while(scanf("%d",&n)==1&&n){		
		printf("Game %d:\n", ++kase);			//数据组
		for(int i=0;i<n;i++)scanf("%d",&a[i]);	//循环将正确值读入数组a中
		for(;;){
			int A=0,B=0;						//重置A,B
			for(int i=0;i<n;i++){				//读取猜测的值
					scanf("%d",&b[i]);
					if(a[i] == b[i]) 			//如果位置正确，则A++
							A++;
			}
			if(b[0]==0)							//判断第一个是否为0，为0则退出循环
				break;							
			for(int d=1;d<=9;d++){				//遍地所有数字
				int c1=0,c2=0;
				for(int i=0;i<n;i++){			//如果这个数字同时出现在A和B中，取他们之间的最小值，则为这个数字对B的贡献
					if(a[i]==d)c1++;
					if(b[i]==d)c2++;
				}
				if(c1>c2)B+=c2;					//取最小的值
				else B+=c1;
			}
			printf("    (%d,%d)\n",A,B-A);		//B-A，B为共同次数，A为正确次数
		} 
	}
	return 0;
}