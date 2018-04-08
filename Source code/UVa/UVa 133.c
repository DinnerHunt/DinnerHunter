//救济金发放 UVa133 2017.6.26

#include <stdio.h>
#define maxn 25
int n,k,m,a[maxn];

int go(int p,int d,int t){					
	while(t--){									//走x部
												//(p+d+n-1)%n+1 因为逆向所以要+n 然后取余n 因为从1开始的，所以要开始减一，取余后加一
		do{p=(p+d+n-1)%n+1}while(a[p]==0);		//如果当前位置没人（则为零，则再走一步）
	}
	return p;
}

int main(){
	while(scanf("%d%d%d",&n,&k,&m)==3&&n){			
		for(int i=1;i<=n;i++)a[i]=i;
		int left=n;								//还剩多少人没有出列
		int p1=n,p2=1;
		while(left){
			p1=go(p1,1,k);						//A顺时针走K步
			p2=go(p2,-1,m);						//B顺时针走m步
			printf("%3d",p1);left--;			//输出A的位置
			if(p2!=p1){printf("%3d",p2);left--;};	//如果A,B的位置不同，则输出B的位置
			a[p1]=a[p2]=0;						//将AB的位置改成0
			if(left)							//如果还未结束，则输出，号
				printf(",");
		}
		printf("\n");
	}
	return 0;
}