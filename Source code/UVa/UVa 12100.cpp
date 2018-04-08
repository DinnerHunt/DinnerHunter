//UVa 12100 打印队列 Printer Queue
#include <bits/stdc++.h>
using namespace std;

priority_queue <int> PQ;
queue<int>	Q;
int a,b,ti,x,y;

void read(){
	cin >> a >> b;
	for(int i=0;i<a;i++){
		cin >> x;
		if(i==b){
			y = x;
			Q.push(0);
			PQ.push(x);
		}
		else{
			Q.push(x);
			PQ.push(x);
		}
	}
}

void timer(){
	int i,j;
	while(PQ.top()!=y){
		i=PQ.top();
		PQ.pop();
		while(Q.front()!=i){
			Q.push(Q.front());
			Q.pop();
		}
		Q.pop();
		ti++;
	}
	while(Q.front()!=0){
		if(Q.front()==y)
			ti++;
		Q.pop();
	}
	ti++;
}

void clear(){
	while(!Q.empty()){
		Q.pop();
	}
	while(!PQ.empty()){
		PQ.pop();
	}
}

int main(){
	int number;
	cin >> number;
	while(number--){
		ti = 0;
		read();
		if(a == 1)
			printf("1\n");
		
        else{
			timer();
			printf("%d\n",ti);
        }
        clear();
	}

	return 0;
}