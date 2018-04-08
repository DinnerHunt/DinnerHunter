//P1190 接水问题
//DinnerHunt
#include <cstdio>
#include <queue>
using namespaces std;
int main(){
	int x,y,k=0,z;
	priority_queue<int,vector<int>,greater<int> > que;
	scanf("%d %d",&x,&y);
	for(int i=0;i<x;i++){
		scanf("%d",&z);
		if(k<m){
			k++;
			que.push(z);
		}
		else{
			z += que.top();
			que.pop();
			que.push(z);
		}
	}
	k=0;
	while(!que.empty()){
		k+=que.top();
		que.pop();
	}
	printf("%d",k);
	return 0;
}