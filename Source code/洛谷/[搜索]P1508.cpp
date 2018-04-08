//P1508 Likecloud-吃,吃,吃 
//DinnerHunt
#include <iostream>
#include <cstdio>
using namespace std;
inline int max(int x,int y){
	return x>y?x:y;
}
int G[205][205],flag[205][205],ans;
const int maxn = 205;
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			scanf("%d",&G[i][j]);
	flag[x+1][y/2+1]=1;
	for(int i=x+1;i>0;i--)
		for(int j=1;j<=y;j++)
			if(flag[i][j]){
				if(j>1){
					flag[i-1][j-1] = max(flag[i-1][j-1],G[i-1][j-1]+flag[i][j]);
					ans = max(flag[i-1][j-1],ans);
				}
				if(j<y){
					flag[i-1][j+1] = max(flag[i-1][j+1],G[i-1][j+1]+flag[i][j]);
					ans = max(flag[i-1][j+1],ans);
				}
				flag[i-1][j] = max(flag[i-1][j],G[i-1][j]+flag[i][j]);
				ans = max(flag[i-1][j],ans);
			}
    
        
	printf("%d",ans-1);
	return 0;
}