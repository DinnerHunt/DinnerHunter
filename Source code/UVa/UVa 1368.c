//DNA序列 UVa1368 

#include <stdio.h>
int more(int A,int C,int G,int T){
    int arr[4]={A,C,G,T};
    int i=0,max=arr[0],lost=0;  
    while(i<4){
        if(arr[i]>max){
            max=arr[i];
            lost=i;
        }
        i++;
    }
    return lost;
}
char swap(int x){
    switch(x){
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';       
    }
    
}
int main(){
	int second,dd=0;
	scanf("%d",&second);
	while(second--){
		int x,y,i=0,j,post=0;
		scanf("%d %d",&x,&y);
        getchar();
		char arr[x][y];
        char list[y];
		while(i<x)
		    gets(arr[i++]);
        if(dd)
            printf("\n");
        dd=1;
        for(j=0;j<y;j++){
            int A=0,C=0,G=0,T=0;
            for(i=0;i<x;i++){
                switch(arr[i][j]){
                    case 'A':
                        A++;
                        break;
                    case 'C':
                        C++;
                        break;
                    case 'G':
                        G++;
                        break;
                    case 'T':
                        T++;
                        break;
                }
            }
            int did[4]={A,C,G,T};
            int sy=more(A,C,G,T);
            post+=x-did[sy];
            list[j]=swap(sy);
            //printf("%d%d%d%d\n",A,C,G,T);
        }
        list[j]='\0';
        printf("%s\n",list);
        printf("%d",post);
	}
	return 0;
}





输出两个值，一个是字符串，一个是距离，也就是不符合的个数
字符串的各个位可以通过求每列的最大值得到，
距离这里将每列最多的字符出现的个数储存起来，错误数=总数-正确数
#include<cstdio>
#include<cstring>

char DNA[51][1010],s[1100];						//DNA 用来存储给出的序列，s用存储新字符串
int pos[4]= {0,2,6,19},m,n,d[1100];				//pos 用来存ACGT的序列位置.m,n为二维数组的长和宽，d用来储存各个位的最大值
int main()
{
    int t,pd[26];								
    scanf("%d",&t);								//
    while(t--)
    {
        memset(s,0,sizeof(s));					//数组s和d清空
        memset(d,0,sizeof(d));
        scanf("%d %d",&m,&n);
        for(int i = 0; i < m; i++)
            scanf("%s",DNA[i]);
        for(int j = 0; j < n; j++)				//从第一列开始枚举
        {
            memset(pd,0,sizeof(pd));			//格式化pd
            for(int i = 0; i < m; i++)			
            {
                pd[DNA[i][j]-'A']++;			//从第一行开始枚举，存储值在字母表中的位置
            }
            int max = 0;						//重置最大的值
            for(int i = 0; i < 4; i++)
            {
                if(max < pd[pos[i]])			//pd[pos[i]]的值是当前字母出现的次数
                {
                    max = pd[pos[i]];			//如果次数大于现在的次数，则，maxf赋值为pd[pos[i]];
                    s[j] = pos[i]+'A';			//将s[j]
                }
            }
            d[j] = max;							//将最大的值存入d[j];
        }
        puts(s);								//输出字符串
        int temp=0;							
        for(int i = 0; i < n; i++)				
            temp += d[i];						//将值求和
        printf("%d\n",m*n-temp);				//输出错误的值
    }
    return 0;
}