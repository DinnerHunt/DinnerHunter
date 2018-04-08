//POJ 2386 Lake Counting 
#include <cstdio>
using namespace std;
const int maxn = 100+5;
char arr[maxn][maxn];
int x,y;
void dfs(int a,int b){
	arr[a][b]='.';

	for(int i=-1;i<=1;i++)
		for(int j =-1 ;j<=1;j++){
			int dx = a+i; dy=b+j;
			if(dx>=0&&dx<x&&dy>=0&&dy<y&&arr[dx][dy]=='W') dfs(dx,dy);
		}
	return ;
}
int main(){
	while(scanf("%d %d",&x,&y)==2&&x&&y){
		for(int i=0;i<x;i++)
				cin >> arr[i];
		int n=0;
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				if(arr[i][j]=='W'){
					dfs(i,j);
					n++;
				}
		print("%d\n",n);
	}
	return 0;
}