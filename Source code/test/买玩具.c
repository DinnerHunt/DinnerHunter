#include <stdio.h>
int sum(int x){								//判断当前买了多少玩具
    int sum=0;
    while(x){
        if(x&1)
            sum++;
        x>>=1;
    }
    return sum;
}
int main(){
    int people,money,kind;
    int arr[people][kind];					//用来储存孩子们的需求
    scanf("%d%d%d",&people,&money,&kind);	//读取儿童数量，购买玩具数，玩具种类
    int i,j;								
    for(i=0;i<people;i++){					//循环将数据存入变量
        scanf("%d",&arr[i][0]);
        for(j=1;j<arr[people][0];j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int d,p=0,max=0;						//d存储当前枚举值，p存储当前情况满足孩子的数量。max存储最大量
    for(d=0;d<(1<<kind);d++){				//枚举所有玩具的购买情况
        
        p=0;										//重置p的值
        if(sum(d)<=money){					//如果购买玩具，即1的数量小于购买能力，则进行下一步判断
            for(i=0;i<people;i++){			//枚举每个儿童
                int m=0;					//用来判断是否满足孩子的所有需求
                for(j=1;j<arr[i][0];j++){		//枚举孩子的需求
                    if((d&(1<<arr[i][j]))==0)	//如果其中一个不满足，则更改m
                        m=1;
						
                }
                if(m==0)					//如果m未被更改，则满足当前孩子的需求
                    p++;
                //printf("%d ",sum(d));
            }
            //printf("%d %d\n",p,d);
        }
		if(p>max)									//循环后，判断当前满足孩子数量是否大于之前存储的数量
            max=p;
		//printf("%d",&max);
    }
    printf("%d",o);
    return 0;
}