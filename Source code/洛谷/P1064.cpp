#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int maxd =10005;
int dp[maxd],money,n;
typedef pair<int,int> P;
vector<P> vet[100];

int main(){
	int a,b,c;
	scanf("%d %d",&money,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(!c)
			vet[i].push_back(P(a,b*a/10));
		else{
			vet[c].push_back(P(vet[c][0].first+a,vet[c][0].second+a*b/10));
			if(vet[c].size()==3)
				vet[c].push_back(P(vet[c][1].first+a,vet[c][1].second+a*b/10));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=money;j>0;j--)
			for(int k=0;k<vet[i].size();k++)
				dp[j] =  max(dp[j],dp[j-vet[i].first]+vet[i].second);
	printf("%d",dp[money]);
	return 0;
}