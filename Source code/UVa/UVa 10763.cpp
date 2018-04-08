//UVa 10763 交换学生 Foreign Exchange
#include <cstdio>
#include <iostream>
#define maxn 500005
using namespace std;

int list[maxn];
void init(){
	for(int i=0;i<=maxn;i++)
		list[i]=i;
}
bool OK(){
    for(int i=0;i<=maxn;i++)
        if(list[i]!=i){
        	printf("%d %d",list[i],i);
            return false;
        }
    return true;
}
void swap(int x,int y){
	list[x]+=list[y];
	list[y]=list[x]-list[y];
	list[x]-=list[y];
}
int main(){
	int number;
	while(cin >> number& &number){
		init();
		int a,b;
		while(number--){
			cin >> a >> b;
			swap(a,b);
		}
		if(OK())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}