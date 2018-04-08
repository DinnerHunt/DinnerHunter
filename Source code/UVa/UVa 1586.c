//分子量 UVa1586 2017.6.21

#include <stdio.h>
#include <string.h>
#include <ctype.h>
double mass[4];

int main(){
    memset(mass, 0, sizeof(mass));  
    mass['C'] = 12.01;  
    mass['H'] = 1.008;  
    mass['O'] = 16.00;  
    mass['N'] = 14.01;  
	int x;
	char c;
	scanf("%d",&x);
	c=getchar();
	while(x--){
		int p=0;
		double sum=0;
        char n='0';
		while(scanf("%c",&c)!=EOF){
            if(c=='\n')
                break;
			if(isdigit(c)){
                if(p!=0){
                    p=p*10+(c-'0');
                    //printf("%d ",p);
                }
                else{
				    p=c-'0';
                }
            }
			else{
                if(n!='0'){
                    if(p!=0){
                        while(p--){
					        sum+=mass[n];
                        }
                    }
                    else
                        sum+=mass[n];
                }
                p=0;
				n=c;
            }
		}
        if(n!='0'){
                    if(p!=0){
                        while(p--){
					        sum+=mass[n];
                        }
                    }
                    else
                        sum+=mass[n];
                }
        printf("%.3lf\n",sum);
	}
    return 0;
}