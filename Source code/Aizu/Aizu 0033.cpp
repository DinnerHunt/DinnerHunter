//Aizu 0033
//DinnerHunt
#include <cstdio>
#include <stack>
using namespace std;
int n,k,flag;
int main(){
	scanf("%d",&n);
	while(n--){
		stack<int> stk1,stk2;
		stk1.push(0);
		stk2.push(0);
		flag=1;
		for(int i=0;i<10;i++){			
			scanf("%d",&k);
			int a=k-stk1.top();
			int b=k-stk2.top();
			if (a<0&&b<0) flag=0;
			else if((0<a&&a<b)||(b<0)) stk1.push(k);
			else stk2.push(k);
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}