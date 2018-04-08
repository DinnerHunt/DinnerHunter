//生成元 UVa1583 2017.6.15

#include <stdio.h>
#include <string.h>
#define maxn 100005
int ans[maxn];
int main(){
	int T,x;
	memset(ans,0,sizeof(ans));	//用0填充数组
	for(int m=1;m<maxn;m++){	//循环从1开始至100005,将所有生成元数放入数组中
		int x=m;int y=m;		//y为生成元后的数
		while(x>0){
			y+=x%10;
			x/=10;
		}
		if(ans[y]==0||m<ans[y])	//如果生成元的数ans[y]为0，h或者 m<生成元，则将生成元的元数放入数组
		ans[y]=m;
	}
	scanf("%d",&T);				
	while(T--){
		scanf("%d",&x);
		printf("%d\n",ans[x]);	//循环调用输出
	}
return 0;
}