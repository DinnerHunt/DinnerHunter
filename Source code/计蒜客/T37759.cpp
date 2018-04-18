#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[3030][3030];
int main(){
    string str1,str2;
    cin >> str1;
    str2=str1;
    int len=str1.size();
    reverse(str2.begin(),str2.end());
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        {
            if(str1[i]==str2[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    cout << len - dp[len][len];
    
    return 0;
}