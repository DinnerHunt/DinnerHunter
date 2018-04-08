//P1145 约瑟夫
//DinnerHunt
#include <cstdio>
using namespace std;
int n;
bool dfs(int size,int k,int now){
	if(size==0) {
	    printf("%d",k);
	    return true;
	}
	now = (now+k-2)%(size+n)+1;
	if(now>n)  return dfs(size-1,k,now);
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=1000;i++)
		if(dfs(n,i,1)) break;
	return 0;
}