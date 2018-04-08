//UVa 804
//Petri网模拟 Petri Net Simulation
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 120;
int NP[maxn];
int NT[maxn][maxn];
int n,m,count,number;
char str[10];
void check(){
	for(int i=1;i<=m;i++){
		int flag = 1;
		for(int j=1;j<=n;j++){
            //printf("%d %d\n",NP[j],NT[i][j]);
			if(NP[j]+NT[i][j]<0){
				flag=0;
				break;
			}
		}
		if(flag){
			for(int j=1;j<=n;j++)
				NP[j]+=NT[i][j];
			count++;
			if(count == number) return;
			check();
			return;
		}
	}
}
int main(){
	int flag=1;
	while(scanf("%d",&n)==1&&n){
		memset(NT,0,sizeof(NT));
		count = 0;
		for(int i=1;i<=n;i++)
			scanf("%d",&NP[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int k;
			while(cin>>k&&k){
				if(k<0)
				NT[i][~k+1]--;
				else
				NT[i][k]++;
			}
		}
		scanf("%d",&number);
		check();
		if(count == number)
			printf("Case %d: still live after %d transitions\n",flag++,number);
		else 
			printf("Case %d: dead after %d transitions\n",flag++,count);
		printf("Places with tokens:");
		for(int i=1;i<=n;i++){
			if(NP[i])
				printf(" %d (%d)",i,NP[i]);
		}
        printf("\n\n");
	}
	return 0;
}

2017/12/4

思路

阅读理解题
这里阐明一下题意 给的第一个数表示的是有N个库 然后接下来N个数表示 1-N 每个数初始有几个token;
然后接下来给一个数表示有NT个变迁规则，规则覆盖的变量不限，负数为出token，正数为入token
最后一个数k表示上述规则是否可以执行K次。
执行规则为是否满足任意一个变迁规则，如果满足则进行变迁，然后执行次数加一，再次进行执行
如果能执行K次，则输出Case %d(第条规则): still live after k(次) transitions
如果不行则输出，Case %d(第条规则): dead after k(变迁次数) transitions
然后输出Places with tokens: (%d (%d)) 等执行完后，各个库所剩多少token;


代码构思

直接模拟就好
用个数组储存各个规则，然后循环判断每个规则是否可执行，如果可以则执行下次check，执行到count则退出，如果不能执行了也直接退出
最后输出执行次数和剩余token