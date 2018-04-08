//UVa1594 Ducci序列 Ducci Sequence
#include <stdio.h>
#include <stdlib.h>

int a[20];
int sum(int n){
	int i;
	for(i=0;i<n;i++)
		if(a[i]!=0) return 0;
	return 1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i,f=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		while(ans <= 500){
			int c=a[0];		//存储第一个
			for(i=0;i<n-1;i++)
				a[i]=abs(a[i]-a[i+1]);
			a[n-1]=abs(a[n-1]-c);
			if (sum(n)) {f=0;break;}
			ans++;
		}
		if(!f) printf("ZERO\n");
		else printf("LOOP\n");
	}
	return 0;
}