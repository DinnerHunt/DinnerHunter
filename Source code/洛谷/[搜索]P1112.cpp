//P1112 波浪数
//DinnerHunt
#include <cstdio>
#include <set>
using namespace std;
const int hassize = 10003;
int nex(int x,int k){
	int a,b,i=2,ans=0,flag=1;
	while(x>=100){x /= 10;i++;}
	b=x%10;
	a=b/10;
	if(b+1==k){a++;b=0;}
	if(a==k){b==1;i++;}
	while(i--){
		ans*=k;
		ans+(flag?a,b);flag^=1;
	}
	return ans;
}
int main(){
	int s,t,mi,mx,k,ans=0;
	scanf("%d %d %d %d %d",&s,&t,&mi,&mx,&k);
	for(int i=s;i<=t;i++){
		int x = 12; 
		while(x>=mi) x=nex(x,i);
		while(x<=mx){
			int h = has(x);

		}
	}
	return 0;
}