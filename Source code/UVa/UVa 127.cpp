//UVa 127
//"Accordian" Patience 纸牌游戏
//DinnerHunt
#include <cstdio>
#include <stack>
using namespace std;
char str[3];
stack<char *> stk[60];						//模拟各个牌堆
int left[60],right[60],number;				//模拟链表
int mod(int x,int y){						//match 操作
	char *s1 = stk[x].top();
	char *s2 = stk[y].top();
	if(s1[1]==s2[1]||s1[0]==s2[0]){
		stk[x].push(s2);stk[y].pop();
		if(stk[y].empty()){
			right[left[y]] = right[y];
            if(right[y])
			left[right[y]] = left[y];
			left[y] = 0;
            right[y] = 0;
			number--;
		}
		return 1;
	}
	return 0;
}
void check(){								//判断是否可以match
	for(int i=1;i<=52;i++){
		if(left[i]){
			int flag=0;
			if(left[left[left[i]]]){
				if(mod(left[left[left[i]]],i)) flag=1;
            }
			if(!flag)
				if(mod(left[i],i)) flag=1;
			if(flag)
			{
				check();
				return;
			} 
		}
	}
}
void init(){								//洗牌，初始化
    for(int i=1;i<=52;i++)
        while(!stk[i].empty())
            stk[i].pop();
	number = 52;
	for(int i=1;i<=52;i++)
		left[i] = i-1;
	left[0]=0;
	for(int i=0;i<52;i++)
		right[i] = i+1;
	right[52]=0;
}
int main(){
	while(scanf("%s",str)==1){
        if(str[0]=='#') break;
		init();
		stk[1].push(str);
		for(int i=2;i<=52;i++)						
		{
            char *k;
            k = new char [10];
			scanf("%s",k);
			stk[i].push(k);
		}
		check();
		if(number ==1)								//格式坑点，不止一堆的时候要输出piles
			printf("%d pile remaining:",number);
		else 
			printf("%d piles remaining:",number);
		int k=1;
		for(int i=1;i<=number;i++,k=right[k])
			printf(" %d",stk[k].size());
        printf("\n");
        
	}
	return 0;
}