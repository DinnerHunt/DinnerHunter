//P1118 luogu
//DinnerHunt
#include <iostream>
int s[15][15];
int f[15],flag=0,;
void init()
{
	s[1][1]=1;
	for(int i=2;i<=12;i++)
		for(int j=1;j<=i;j++)
			s[i][j] = s[i-1][j-1]+s[i-1][j];
}
int dfs(int sum,n){
	if(flag) return ;
	if( )
}
int main(){
	ios::sync_with_stdio(false);
	int n,sum;
	cin >> n >> sum;
	dfs(sum,n);
	return 0;
}