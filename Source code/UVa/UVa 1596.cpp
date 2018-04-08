//UVa 1596   找bug  Bug Hunt
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;
typedef long long ll;
pair<char,ll>ha;            //记录数组的下标及名称
map<char,ll>Count;          //记录每个数组名的最大值
map<pair<char,ll>,ll>num;   //记录每个数组单元的值
string trans(string s){     //把中括号去掉
   char ss[10000];
   memset(ss,0,sizeof(ss));
   int i, j = 0, len = s.length();
   for(i = 0; i < s.length(); i++)
      if(s[i] != '[' && s[i] != ']') ss[j++] = s[i];
   ss[j] = 0;
   string s1 = ss;
   return s1;
}
ll get_count(string s){      //得到数组元素的值并判断
   int len = s.length(), temp = 0;
   string s1 = s;
   for(int i = 0; i < len; i++){
      char c = s[i];
      if(isalpha(c)) if(!Count.count(c)) return -1;   //没有定义的数组，直接返回
      if(isalpha(c)) s[i] = ' ';
      if(isdigit(c)) {temp = i;break;}
   }
   stringstream ss(s);
   ll x;
   ss >> x;
   for(int i = temp-1; i >= 0; i--){
      char c = s1[i];
      ha.first = c; ha.second = x;
      if(!num.count(ha)) return -1;
      x = num[ha];
   }
   return x;
}
int main()
{
    string s;
    int i,j,k;
    vector<string>code;
    while(cin >> s && s[0] != '.'){
        Count.clear();
        num.clear();
        code.clear();
        code.push_back(trans(s));
        int yes = 1;
        while(cin >> s && s[0] != '.')
            code.push_back(trans(s));
        int len = code.size();
        for(i = 0; i < len; i++){
            k = code[i].find('=');
            if(k == std::string::npos){
               string s1 = code[i].substr(1);
               char c = code[i][0];
               ll x = get_count(s1);
               if(x == -1) {cout << i+1 << endl;yes = 0;break;}
               Count[c] = x;
            }
            else{
               string s1 = code[i].substr(1,k-1);
               string s2 = code[i].substr(k+1);
               char c = code[i][0];
               ll x = get_count(s1), y = get_count(s2);
               if(!Count.count(c) || x == -1 || y == -1 || x >= Count[c]){cout << i+1 << endl; yes = 0; break;}
               ha.first = c; ha.second = x;
               num[ha] = y;
            }
        }if(yes == 1)cout << "0\n";
    }
    return 0;
}
