// UVa10935 卡片游戏 Throwing cards away I
#include <cstdio>
#include <iostream>

using namespace std;

int Q[10000];
int main(){
	int number;
	while(cin >> number &&number){
		for(int i=0;i<=number;i++)
			Q[i] = i;
		int head = 1,tail = number, first = 1;
		printf("Discarded cards:");
		while(head < tail){
			if(!first) printf(",");
			printf(" %d",Q[head++]);
			Q[++tail] = Q[head++];
			first = 0; 
		}
		printf("\nRemaining card: %d\n",Q[head]);
	} 
	return 0;
}
