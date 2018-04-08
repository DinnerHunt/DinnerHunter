//得分 UVa1585 2017.6.21
#include <stdio.h>
int main(){
	int n,m=0;
    char z;
    scanf("%d",&n);
    z=getchar();
    while(n--){
    int x=1,y=0;
    //if(m==1)
    //    printf("\n");
    //m=1;
	while(scanf("%c",&z)!=EOF){
        if(z=='\n')
            break;
		if(z=='O'){
			y+=x;
			x++;
		}
		else
			x=1;
	    }
	printf("%d\n",y);
    }
	return 0;
}