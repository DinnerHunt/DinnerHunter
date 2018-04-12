//POJ 3617
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
char str[2000],ch;
int main(){
    int n;
	while(scanf("%d",&n)==1){		for(int i=0;i<n;i++){
			scanf(" %c",&str[i]);
		}
	    int a=0,b=n-1,ans=0;
	    while(a<=b){
	        bool left = false;
	        for(int i=0;a+i<=b;i++){
	            if(str[a+i] < str[b-i]){
	                left = true;
	                break;
	            }
	            else if(str[a+i] > str[b-i]){
	                left = false;
	                break;
	            }
	        }
	        if(left) printf("%c",str[a++]);
	        else printf("%c",str[b--]);
	        ans++;
	        if(ans==80){  
                printf("\n");  
                ans=0;  
            }     
	    }
	    printf("\n");
	}
	return 0;
}