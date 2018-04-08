#include <stdio.h>

void scan(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int x=a+d,y=b+e,z=c+f;
	y+=z/60;
	x+=y/60;
	printf("%d %d %d\n",x,y%60,z%60);

}

int main(){
	int number;
	scanf("%d",&number);
	while(number--){
		scan();
	}
	return 0;
}