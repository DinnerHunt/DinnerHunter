#include <stdio.h>

int niu(int x){
	if(x>3)
		return niu(x-1)+niu(x-3);
	else if(x==3)
		return 3;
	else if(x==2)
		return 2;
	else 
		return 1;
}

int main(){
	int number;
	while(scanf("%d",&number)!=EOF&&number!=0)
		printf("%d\n",niu(number));
	return 0;
}