//UVa 806
//Spatial Structures 空间结构
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 70;			
char G[maxn][maxn];
vector<int> vet;
int pow(int x,int y){
	int z =1;
	for(int i=0;i<y;i++)
		z *= x;
	return z;
}
int format(long long id){							//路径格式化成10进制
	long long k=id,l=0;
	int key=0,i=0;
	while(k){l=l*10+k%10;k/=10;}	//记得翻转
	while(l){
		key+= (l%10)*pow(5,i++);
		l/=10;
	}
	return key;
}
long long reformat(int id){							//10进制格式化成路径
	int k = id,i=0;
	long long key =0;
	while(k){
		key+=(k%5)*pow(10,i++);
		k/=5;
	}								//不需要翻转，可以直接数转矩
	//printf("%d ",key);
	return key;
}
void build(int a,int b,int c,int d,long long id){		//建树（长起，长终，宽起，宽终）
	int x=0,y=0;										//代表两种颜色
	for(int i=a;i<=b;i++)
		for(int j=c;j<=d;j++){
			if(G[i][j]=='0') x++;						
			if(G[i][j]=='1') y++;
			if(x&&y){									//如果都有，则继续递归遍地
				build(a,(b+a-1)/2,c,(d+c-1)/2,id*10+1);
				build(a,(b+a-1)/2,(d+c-1)/2+1,d,id*10+2);
				build((b+a-1)/2+1,b,c,(d+c-1)/2,id*10+3);
				build((b+a-1)/2+1,b,(d+c-1)/2+1,d,id*10+4);
				return ;								// ***递归完后直接退出
			}	
		}
	if(y)
		vet.push_back(format(id));						//将路径加入vet
}
void dismantle(int a,int b,int c,int d,long long id){
    if(id){												//判断是否到达路径所要表达的范围
        int k = id%10;									
        switch(k)
        {
            case 1:
                dismantle(a,(b+a-1)/2,c,(d+c-1)/2,id/10);
                break;
            case 2:
                dismantle(a,(b+a-1)/2,(d+c-1)/2+1,d,id/10);
                break;
            case 3:
                dismantle((b+a-1)/2+1,b,c,(d+c-1)/2,id/10);
                break;
            case 4:
                dismantle((b+a-1)/2+1,b,(d+c-1)/2+1,d,id/10);
                break;
        }
        return;
    }
    else												//染色
        for(int i=a;i<=b;i++)
            for(int j=c;j<=d;j++)
                G[i][j] = '*';
            
}
int main(){
	int number,flag =1 ;
	char ch;
	while(cin >> number&&number){
        if(flag!=1)printf("\n");						//格式，末行不输出回车
		if(number>0){
			ch = getchar(); 							//因为用fgets 所以用来读多余的回车
			vet.clear();
			for(int i=1;i<=number;i++)
				fgets(G[i]+1,maxn,stdin);				//都从1开始方便理解
			build(1,number,1,number,0);					//开始递归
			printf("Image %d\n",flag++);
			int len = vet.size();
			if(len){
				sort(vet.begin(),vet.end());
				for(int i=0;i<len;i++){
					printf("%d",vet[i]);
                    if((i+1)%12==0||i==len-1) printf("\n");
					else printf(" ");
				}
			}
			printf("Total number of black nodes = %d\n",len);
		}
		else{
            int d;
            number=0-number;
            for(int i=1;i<=number;i++)
                for(int j=1;j<=number;j++)
                    G[i][j]='.';
            while(scanf("%d",&d)==1&&d!=-1)
                dismantle(1,number,1,number,reformat(d));
            printf("Image %d\n",flag++);
            for(int i=1;i<=number;i++){
                for(int j=1;j<=number;j++)
                    printf("%c",G[i][j]);
                printf("\n");
            }
            //printf("\n");
		}
	}
	return 0;
}

2017/12/5