//P1311 选择客栈
//DinnerHunt
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack<int> stk[50];
int arr[50],last[50];
int main(){
	int x,y,z,a,b,j=0,ans=0;
	memset(last,-1,sizeof(last));
	scanf("%d %d %d"，&x,&y,&z);
	for(int i=0;i<;i++){
		scanf("%d %d",&a,&b);
		if(b<=z) j=i;
		if(last[a]!=-1){
			stk.push(last[a]<=j?1:0);
		}
	}
	for(int i=0;i<y;i++){

	}
	printf("%d",ans);
	return 0;
}