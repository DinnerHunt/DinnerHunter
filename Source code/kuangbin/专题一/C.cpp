//kuangbin带你飞 专题一 C
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,flag[200050];
int main(){
		scanf("%d %d",&n,&m);
		queue<int> que;
		que.push(n);
		flag[n]=1;
		while(!que.empty()){
			int k = que.front();
			que.pop();
			if(k==m) {printf("%d",flag[k]-1);break;}
			if(k<0)
				continue;
			if(k<m){
				if(!flag[k+1]) que.push(k+1),flag[k+1]=flag[k]+1;
				if(k<101000)
				if(!flag[k*2]) que.push(k*2),flag[k*2]=flag[k]+1;
	            if(!flag[k-1]) que.push(k-1),flag[k-1]=flag[k]+1;
			}
			else{

				if(!flag[k-1]) que.push(k-1),flag[k-1]=flag[k]+1;
			}
		}
	return 0;
}