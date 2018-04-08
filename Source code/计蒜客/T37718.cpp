//jisuanke T37718 蒜头君的猜想
//DinnerHunt
#include <stdio.h>
#include <string.h>
int arr[8000000];
void init(int k){
    for(int i=1;i<=k;i++)
        arr[i]=1;
	for(int i=2;i*i<=k;i++)
		if(arr[i])
			for(int j=i*i;j<=k;j+=i)
				arr[j] = 0;
}
int main(){
	int n,ans=0;
	scanf("%d",&n);
	init(n);
    for(int i=2;i*2<=n;i++)
        if(arr[i]&&arr[n-i])
            ans++;
	printf("%d",ans);
	return 0;
}