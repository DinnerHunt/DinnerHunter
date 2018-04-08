//追踪电子表格中的单元格 UVa512
//first 
#include <stdio.h>
#include <string.h>
#define maxd 100
#define BIG 10000
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd],cols[maxd];	//r,c用来储存行和列的宽
														//cols用来存储命令的数据

//移动数组中的数
void copy(char type,int p,int q){
	if(type == 'R'){									//如果是行操作,p是目标位置行，q是原行
		for(int i=1;i<=c;i++)							//一个个将数字复制到过去
			d[p][i]=d2[q][i];							//将d2中的数字复制到d
	}
	else{
		for(int i=1;i<=c;i++)							//如果是列，则行列位置调换
			d[i][p]=d2[i][q];
	}
	
}


//删除操作										
void del(char type){
	memcpy(d2,d,sizeof(d));								//将d1复制到d2
	int cnt = type == 'R' ? r : c ,cnt2=0;				//如果第二个字母是R，则cnt=行，不然则为列
	for (int i=1;i<cnt;i++){							
		if(!cols[i])copy(type,++cnt2,i);				//如果clos[i]中不是要删除的行，则复制到，cnt++
	}
	if(type == 'R') r=cnt2;else c=cnt2;					//如果是行则，行数=cnt，列数=cnt2;
}			

//插入操作							
void ins (char type){
	memcpy(d2,d,sizeof(d));
	int cnt=type='R' ? r:c,cnt2=0;
	for(int i=1;i<cnt;i++){								//如果是插入行，则插入空行
		if(cols[i]) copy(type,++cnt2,0);				//插入当前行
		copy(typr,++cnt2,i);
	}
}
														
														
int main(){
	int r1,c1,r2,c2,q,kase=0;										
	char cmd[10];										//存储操作命令
	memset(d,0,sizeof(d));
	while(scanf("%d%d%d",&r,&c,&n)==3&&r){				//读取行，列，和命令的数量
		int r0=r,c0=c;
		
		for(int i=1;i<=r;i++)						//将数组d初始化
			for(int j=1;j<c;j++)
				d[i][j]=i*BIG+j;					//各个数除于BIG可以得到行，取余得到列，储存当前数的原位置
		
		//读取操作命令
		while(n--){									//有多少条命令
			scanf("%s",cmd);						//读取命令
			if(cmd[0]=='E'){						//如果是交换单元格的命令
				scanf("%d%d%d%d",&r1,&c1&,&r2,&c2);	//存储4个点，要交换的数的行和列
				int t=d[r1][c1],d[r1][c1]=d[r2][c2],d[r2][c2]=t;
			}
			else{									//否则，则读取第一个参数
				int a,x;
				scanf("%d",&a);					
				memset(cols,0,sizeof(cols));
				for(int i=0;i<a;i++){ scanf("%d",&x);cols[x]=1;}	//循环将后面参数添入数组
				if(cmd[0]=='D')def(cmd[1]);else ins(cmd[1]);		//如果是删除操作，则执行del函数，不然则执行ins函数
			}
		}
		
		
		//格式化储存位置，方便查询
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=r;i++)
			for(int j=1;j<c;j++)
				ans[d[i][j]/BIG][d[i][j]%BIG]=i*BIG+j;	//在原位置上存储新位置的值 d[i][j]/big是原位置的行，i*BIG+j是新位置
		
		
		
		//查询位置
		if(kase>0)printf("\n");
		printf("Spreadsheet #%d\n",++kase);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&r1,&c1);					//要查询的行和列
			printf("Cell data in (%d,%d)",r1,c1);
			if(ans[r1][c1]==0)printf("GONE\n");		//如果查询的值为空，则被删除了
			else  printf("moved to (%d,%d)\n",ans[r1][c1]/BIG,ans[r1][c1]%BIG);	//不然则根据位置查询新值的位置
			
		}
		
	}
	
	return 0;
}