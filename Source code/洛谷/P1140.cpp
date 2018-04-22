#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd =205;
int s1,s2,k1[maxd],k2[maxd],dp[maxd][maxd];
int arr[5][5] = {
 {5,-1,-2,-1,-3},
 {-1,5,-3,-2,-4},
 {-2,-3,5,-2,-2},
 {-1,-2,-2,5,-1},
 {-3,-4,-2,-1,0}
};
char str1[maxd],str2[maxd];
int id(char ch){
	if(ch == 'A') return 0;
	if(ch == 'C') return 1;
	if(ch == 'G') return 2;
	if(ch == 'T') return 3;
}
int main(){
	scanf("%d %s %d %s",&s1,str1+1,&s2,str2+1);
    for(int i=1;i<=s1;i++) k1[i] = id(str1[i]);
    for(int i=1;i<=s2;i++) k2[i] = id(str2[i]);
    for(int i=1;i<=s1;i++) dp[i][0] = dp[i-1][0] + arr[k1[i]][4];
    for(int i=1;i<=s2;i++) dp[0][i] = dp[0][i-1] + arr[k2[i]][4];
    for(int i=1;i<=s1;i++)
    	for(int j=1;j<=s2;j++){
            dp[i][j] = -1e9;
    		dp[i][j] = max(
    						max(dp[i-1][j]+arr[k1[i]][4],dp[i][j-1]+arr[k2[j]][4]),
    					   	max(dp[i][j],dp[i-1][j-1]+arr[k1[i]][k2[j]])
    					   );
        }
    printf("%d",dp[s1][s2]);
	return 0;
}
