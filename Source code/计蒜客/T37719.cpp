//T37719 jisuanke 素数距离
//DinnerHunt
#include <stdio.h>
const int maxn = 8000005;
int arr[maxn];
int a,b;
void init(){
	for(int i=2;i<=b;i++)
		arr[i] = 1;
	for(int i=2;i*i<=b;i++)
		if(arr[i])
			for(int j = i*i;j<=n;j+=i)
				arr[j] = 0;
}
int main(){
	init();
	scanf("%d %d",&a,&b);
	int mx=0,mi=maxn,lx=0,rx=0,li=0,ri=0;
	int nl=0,nr=0;
	for(int i=a;i<=b;i++){
		if(arr[i]){
			if(!nl) nr=i;
			else{
				nl = nr;
				nr = i;
				if(nr-nl>mx){lx=nl;rx=nr;mx = nr-nl;}
				if(nr-nl<mi){li=nl;ri=nr;mx = nr-nl;}
			}
		}
	}
	if(!nl) printf("There are no adjacent primes.");
	else printf("%d,%d are closest, %d,%d are most distant.",li,ri,lm,rm);
	return 0;
}