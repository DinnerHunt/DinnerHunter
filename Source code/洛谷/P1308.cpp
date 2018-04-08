#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
int main(){
    string str1,str2,src;
    int env,ans=0,i;
    getline(cin,src);
    transform(src.begin(), src.end(), back_inserter(str1), ::toupper);
    getline(cin,src);
    transform(src.begin(), src.end(), back_inserter(str2), ::toupper);
    str1=" "+str1+" ";
    str2=" "+str2+" ";
    env=i=str2.find(str1,0);
    if(i==str2.npos) cout << -1;
    else
    {
        while(i!=str2.npos){ans++;i=str2.find(str1,i+1);}
        cout << ans << " " << env;
    }
    return 0;
}