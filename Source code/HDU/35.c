#include <stdio.h>

void cifan(int x,int y){
	int i=1;
	while(y>0){
		i*=x;
		i%=1000；
	}
	printf("%d\n",i);
}

int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y),n||m){
		cifan(x,y);
	}
	return 0;
}