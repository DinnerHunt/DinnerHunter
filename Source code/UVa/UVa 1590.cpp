//IP网络 UVa1590
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int zwym_table[9]={255,254,252,248,240,224,192,128,0};

int main(){
	int ip[4][1024];	//储存4段IP
	int m;
	while(scanf("%d",&m)!=EOF){
			memset(ip,0,sizeof(ip));
			int zwym[4];	//储存4段子网掩码
			int minip[4];	//储存4段IP
			for(int i=0;i<m;i++)	//读取题目给的IP地址
				scanf("%d.%d.%d.%d",&ip[0][i],&ip[1][i],&ip[2][i],&ip[3][i]);


		 	for(int i=0;i<4;i++)
		 	{
		 		int dif=0,x,j;
		 		int p,q;
		 		sort(ip[i],ip[i]+m);	//对4个IP的第i部分进行排序
		 		p=ip[i][m-1];			//p=IP第I段最大部分
		 		q=ip[i][0];				//q=IP第I段最小部分
		 		for(j=1;j<=8;j++){		//模拟位运算，求出当前子网掩码
		 			if(p%2!=q%2)		//如果当前位不同，则进为当前为
		 				dif=j;
		 			p = p/2;
		 			q = q/2;
		 		}
		 		zwym[i]=zwym_table[dif];	//当前段的子网掩码
		 		minip[i]=ip[i][0]&zwym[i];	//当前段的IP为与当前段的子网掩码的值
		 	}

		 	for(int i=0;i<4;i++)	//循环4段子网掩码
		 	{
		 		if(zwym[i]!=255)	//如果当前的段没有全部被掩住
		 		{
		 			for(i = i+1;i<4;i++)	//从下一段开始，将所有的掩码和IP都置0
		 			{
		 				zwym[i]=0;
		 				minip[i]=0;
		 			}
		 			break;
		 		}
		 	
			}
		printf("%d.%d.%d.%d\n",minip[0], minip[1], minip[2], minip[3]);  
        printf("%d.%d.%d.%d\n",zwym[0], zwym[1], zwym[2], zwym[3]);  
	}
	return 0;
}