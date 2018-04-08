#include <stdio.h>
#include <math.h>
int main(){
	double x;
	int y;
	while(scanf("%lf %d",&x,&y)!=EOF){
		double sum=0,;
		while(y--){
			sum+=x;
			x=sqrt(x);
		}		
		printf("%.2lf\n",sum);
	}
	return 0;
}