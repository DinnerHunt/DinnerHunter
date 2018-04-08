//古老的密码 UVa1399 2017.6.26
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 105
char arr1[max];
char arr2[max];
int cmp(const void* a,const void* b){
	return *(int *)a-*(int *)b;
}
int main(){
	while(scanf("%s %s",arr1,arr2)==2){
		int n=strlen(arr1);
		int cnt1[26]={0},cnt2[26]={0};
		for(int i=0;i<n;i++)cnt1[arr1[i]-'A']++;
		for(int i=0;i<n;i++)cnt2[arr2[i]-'A']++;
		qsort(cnt1,26,sizeof(int),cmp);
		qsort(cnt2,26,sizeof(int),cmp);
		int ok=0;
		for(int i=0;i<26;i++)
			if(cnt1[i]!=cnt2[i])
				ok=1;
		if(ok==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}