//P1064 luogu
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
int dp[60][32000];
P arr[65];
P pj[65][3];
int n,m,v,p,q,k=1;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		cin >> v >> p >> q;
		if(q){
			if(!pj[q][1].first) pj[q][1] = P(v,p);
			else pj[q][2] = P(v,p);
		}
		else arr[k++] = P(v,p);
	}
	for(int i=1;i<k;i++){
		v=arr[i].first; p=arr[i].second;
		P q1=pj[i][1],q2=pj[i][2];
		for(int j=1;j<=n;j++)
		{   
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
            if(j<v)continue;
			dp[i][j] = max(dp[i][j],dp[i-1][j-v]+v*p);
			if(q1.first&&j-v>=q1.first) dp[i][j] = max(dp[i][j],dp[i-1][j-v-q1.first]+v*p+q1.first*q1.second);
			if(q2.first&&j-v>=q2.first) dp[i][j] = max(dp[i][j],dp[i-1][j-v-q2.first]+v*p+q2.first*q2.second);
			if(q1.first&&q2.first&&j-v>=q1.first+q2.first) 
				dp[i][j] = max(dp[i][j],dp[i-1][j-v-q1.first-q2.first]+v*p+q1.first*q1.second+q2.first*q2.second);
		}
	}
    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++)
            cout << dp[i][j] << " " ;
        cout << endl;
    }
	return 0;
}