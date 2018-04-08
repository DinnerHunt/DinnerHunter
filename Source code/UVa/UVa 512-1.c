//追踪电子表格中的单元格 UVa512 
#include <stdio.h>
#include <string.h>
#define maxd 10000
struct Command{	
	char c[5];								//操作命令
	int r1,c1,r2,c2;						//如果是交换参数的4个参数
	int a,x[20];							//a操作参数个数，x操作参数
}cmd[maxd];
int r,c,n;

int simulate(int* r0,int* c0){
	for(int i=0;i<n;i++){					//逐条执行命令
		if(cmd[i].c[0]=='E'){				//如果是交换命令
			if(cmd[i].r1==*r0 &&cmd[i].c1==*c0){			//如果在被交换的数中，则进行交换
				*r0 =cmd[i].r2; *c0=cmd[i].c2;
			}
			else if(cmd[i].r2==*r0 && cmd[i].c2==*c0){
				*r0=cmd[i].r1; *c0=cmd[i].c1;
			}
		}
		//其他命令
		else{
			int dr=0,dc=0;					//行列数的变化
			for(int j=0;j<cmd[i].a;j++){	
				int x=cmd[i].x[j];			//当前操作的参数
				if(cmd[i].c[0]=='I'){		//添加操作的变化
					if(cmd[i].c[1]=='R' && x<=*r0) dr++;	//如果是行操作，并且操作的行数小于指令行数，则行数会加一
					if(cmd[i].c[1]=='C' && x<=*c0) dc++;	//列如上
				}
				else{						//删除操作的变化
					if(cmd[i].c[1]=='R' && x==*r0) return 0;//如果正好是当前这行，则被删除
					if(cmd[i].c[1]=='C' && x==*c0) return 0;
					if(cmd[i].c[1]=='R' && x<*r0) dr--;		//如果小于则减减；
					if(cmd[i].c[1]=='C' && x<*c0) dc--;
				}
			}
			*r0 += dr;*c0 += dc;							//将变量加上参数
		}
	}
	return 1;
}

int main(){
	int r0,c0,q,kase=0;
	while(scanf("%d%d%d",&r,&c,&n)==3&&r){
		for(int i=0;i<n;i++){					//循环读取命令
			scanf("%s",cmd[i].c);
			if(cmd[i].c[0]=='E'){				//如果是交换操作
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2);	//储存各个数
			}
			else{							
				scanf("%d",&cmd[i].a);			//储存个数
				for(int j=0;j<cmd[i].a;j++)		
						scanf("%d",&cmd[i].x[j]);	//将操作参数传入x数组
			}
		}
		
		
		if(kase > 0) printf("\n");
		printf("Spreadsheet #%d\n",++kase);			//数据编号
		
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&r0,&c0);
			printf("Cell data in (%d,%d) ",r0,c0);	//原数据位置
			if(!simulate(&r0,&c0)) printf("GONE\n");	//看看新位置是否存在，不存在则输出空
			else printf("moved to (%d,%d)\n",r0,c0);
			
		}
		
	}
	return 0;
}