#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 1<<18;
int n,m,dp[maxd];
vector<int> spend,number;
bool flag[maxd];
struct node{
	int x,y;
}arr[20];
bool grep(int x,int y){			//如果x是i的子集
	return x|y==y;
}
int find(int x,int y){
	return x^y;
}
bool check(int x){
	int s=0;
	for(int i=0;(1<<i)<=x;i++)
		if(x&(1<<i))
			s+=arr[i].y;
	if(s>n) return false;
	return true;
}
int count(int x){				//统计花费	
	int s=0;
	for(int i=0;(1<<i)<=x;i++)
		if(x&(1<<i))
			s= max(arr[i].x,s);
    return s;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&arr[i].x,&arr[i].y);
    }
	for(int i=1;i<(1<<m);i++)
		if(check(i)){
			number.push_back(i);
			spend.push_back(count(i));
		}
	memset(dp,1,sizeof(dp));
    dp[0] = 0;
	for(int i=1;i<(1<<m);i++)
		for(int j=0;j<spend.size();j++){
			int k = number[j];
			if(k<=i&&grep(k,i))
				dp[i] = min(dp[i],dp[find(i,k)]+spend[j]);
		}
	printf("%d",dp[(1<<m)-1]);
	return 0;
}