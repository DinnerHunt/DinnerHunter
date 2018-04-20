#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int maxd =105;
int dp[maxd][maxd][maxd],G[maxd],mp[maxd],ans;
bool check(int x,int y){
	return (x|y) == y;
}
bool ok(int x){
	return  !((x&(x>>1))||(x&(x>>2)));
}
bool grep(int x,int y){
	return !(x&y);
}
int count(int x){
	int s=0;
	while(x){
		s+=(x&1);
		x>>=1;
	}
	return s;
}
int main(){
	int n,m,len=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			char ch;
			cin >> ch;
			if(ch=='P')G[i]+=1<<(m-j-1);
		}
	for(int i=0;i<(1<<m);i++)
		if(ok(i)) mp[len++] = i;

	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
		 	if(check(mp[i],G[0])&&check(mp[j],G[1])&&grep(mp[i],mp[j]))
		 		dp[1][i][j] = count(mp[i])+count(mp[j]);

	for(int i=2;i<n;i++)
		for(int j=0;j<len;j++)
			if(check(mp[j],G[i]))
				for(int k=0;k<len;k++)
					if(check(mp[k],G[i-1])&&grep(mp[j],mp[k]))
						for(int l=0;l<len;l++)
							if(check(mp[l],G[i-2])&&grep(mp[j],mp[l])&&grep(mp[k],mp[l]))
								dp[i][k][j] = max(dp[i][k][j],dp[i-1][l][k]+count(mp[j]));
                            
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			ans = max(ans,dp[n-1][i][j]);
    
    printf("%d",ans);
	return 0;
}