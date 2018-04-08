//盒子 UVa1587 2017.6.25
#include <stdio.h>
#include <stdlib.h>
int arr[12];
int lost[12];
int arr1[4];
int cmp(const void* a,const void* b)
    return *(int *)b - *(int *)a;
int main(){
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF){
		int i=0,j=0,ok=0;
		while(i<12){
			if(x>y){
				arr[i++]=x;
				arr[i++]=y;
			}
			else{
				arr[i++]=y;
				arr[i++]=x;
			}
			if(i<12)
			scanf("%d %d",&x,&y);
		}
        for(i=0;i<12;i++)
            lost[i]=arr[i];
        qsort(lost,12,sizeof(int),cmp);
		/*
        if((lost[0]==lost[3])&&(lost[4]==lost)[7]&&(lost[8]==lost[11])&&lost[3]!=lost[4]&&lost[7]!=lost[8])
        {
			for(i=0;i<6;i++){
				if(arr[i]==lost[])
			}
        }*/
		for(i=0;i<12;i++)
			printf("%d ",post[i]);
        
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct face{
    int x, y;
}a[6];
bool check()
{
    if(memcmp(a, a+1, sizeof(face)) || memcmp(a+2, a+3, sizeof(face)) || memcmp(a+4, a+5, sizeof(face))) return false;
    if(a[0].x!=a[2].x || a[0].y!= a[4].x || a[2].y!=a[4].y) return false;
    return true;
}
int main()
{
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y){
        for(int i = 0; i < 6; ++i)
            if(a[i].x < a[i].y)
                swap(a[i].x, a[i].y);
        sort(a, a+6, [](const face a, const face b) {return a.x==b.x ? (a.y > b.y) : (a.x > b.x);});
        printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}