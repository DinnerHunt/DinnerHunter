//P1118 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int n,sum,yh[15][15],us[15],flag=0,tr[15];
void init(){
	yh[1][1]=1;
	for(int i=2;i<=14;i++)
		for(int j=1;j<=i;j++)
			yh[i][j] = yh[i-1][j]+yh[i-1][j-1];
}
void dfs(int s,int ans){
	if(flag||ans>sum) return;
	if(s==n+1)
	{
		if(ans==sum)
		{
			for(int i=1;i<=n;i++)
				cout <<tr[i] << " ";
			flag=true;
			return ;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!us[i])
		{
			tr[s]=i;
			ans+=i*yh[n][s];
			us[i] = 1;
			dfs(s+1,ans);
			ans-=i*yh[n][s];
			us[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	init();
	cin >> n >> sum;
	dfs(1,0);
	return 0;
}