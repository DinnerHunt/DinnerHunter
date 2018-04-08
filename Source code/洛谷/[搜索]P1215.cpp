//P1215 母亲的牛奶
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
inline int min(int x,int y){
	return x<y?x:y;
}
priority_queue<int,vector<int>,greater<int> > ans;
int flag[25][25];
int boot[3],baat[3],sum,j,k;

void dfs(int x,int y,int z){
	int kid;
	if(!x)
		ans.push(z);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			baat[0]=x,baat[1]=y,baat[2]=z;
			if(i==j||!baat[i]||baat[j]==boot[j]) continue;
			kid = min(baat[i]+baat[j],boot[j]) - baat[j];
			baat[i]-=kid; baat[j]+=kid;
			if(flag[baat[0]][baat[1]]) continue;
			flag[baat[0]][baat[1]] = 1;
			dfs(baat[0],baat[1],baat[2]);
		}
}

int main(){
	int x,y,z;	
	scanf("%d %d %d",&boot[0],&boot[1],&boot[2]);
	flag[a][b] = 1;
	dfs(a,b,c);
	while(!ans.empty()){
		printf("%d ",ans.top);
		ans.pop();
	}
	return 0;
}