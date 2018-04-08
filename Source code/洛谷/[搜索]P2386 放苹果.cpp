//P2386 放苹果
//DinnerHunt
#include <cstdio>
using namespace std;
int ans;
void dfs(int x,int y){
	if(y==1||x==0){
		ans++;
		return;
	}
	if(x<y) dfs(x,x);
	else {
		dfs(x-y,y);
		dfs(x,y-1);
	}
}
int main(){
	int count,a,b;
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		ans = 0;
		scanf("%d %d",&a,&b);
		dfs(a,b);
		printf("%d\n",ans);
	}
	return 0;
}