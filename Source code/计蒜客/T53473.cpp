//jisuanke  53473  回文
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char arr[1000];
int check(int x,int y){
	int k = x;
	int len=0;
	while(k){
		arr[len++] = k%y;
		k/=y;
	}
    //printf("%d %d\n",x,y);
    //cout << str << endl;
	for(int i=0;i<len/2;i++)
		if(arr[i]!=arr[len-i-1])
			return 0;
	return 1;
}
void init(){
    for(int i=0;i<1000;i++)
        arr[i] = i;
}
int main(){
	int n,m,flag=0;
	scanf("%d",&n);
	init();
    //for(int i=0;i<62;i++)
        //printf("%c ",arr[i]);
	while(n--){
		scanf("%d",&m);
		for(int i=2;;i++)
			if(check(m,i)){
				if(flag++) printf("\n");
				printf("%d",i);
				break;
			}
	}
	return 0;
}