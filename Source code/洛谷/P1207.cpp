//P1207 双重回文数
//DinnerHunt
#include <cstdio>
using namespace std;
int n,s,k;
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
string str;
bool check(int x,int d,int y){
	if(y==10)
		return false;
	str.clear();
	int z=x;
	while(z){
		str+=arr[z%10];
		z/=10;
	}
	int len = str.length();
	for(int i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-i-1])
			return check(x,d,y+1);
	}
	if(d)
		return true;
	return check(x,d+1,y+1)
int main(){
	scanf("%d %d",&n,&s);
	while(n){
		if(check(s,0,2)){
			printf("%d\n",s);
			n--;
		}
		s++;
	}
	return 0;
}