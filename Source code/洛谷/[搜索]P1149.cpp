//P1149 火柴棒等式
//DinnerHunt
#include <cstdio>
using namespace std;
int us[10] = {6,2,5,5,4,5,6,3,7,6};
int n,ans;
void check(int a,int b,int c){
    int k=0;
    int x=a,y=b,z=c;
	do{k+=us[a%10];a/=10;}while(a);
	do{k+=us[b%10];b/=10;}while(b);
	do{k+=us[c%10];c/=10;}while(c);
	if(k==n-4)ans++;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++){
			check(i,j,i+j);
		}
	printf("%d",ans);
	return 0;
}